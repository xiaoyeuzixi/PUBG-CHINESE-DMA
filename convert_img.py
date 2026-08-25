from PIL import Image
import os
import struct

def rgb888_to_rgb565(r, g, b):
    # RGB565 format: RRRRRGGG GGGBBBBB
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)

img_path = r'C:\Users\DOUDOU\Desktop\HP\dma.png'
header_path = r'C:\Users\DOUDOU\Desktop\HP\NetConfig\dma_pic.h'

if not os.path.exists(img_path):
    print(f"Error: {img_path} not found.")
    # Create a dummy image for testing if real one is missing, but user said it exists.
    # I'll create a simple gradient if it doesn't exist, just in case.
    print("Creating dummy image for testing...")
    img = Image.new('RGB', (128, 160), color = 'red')
else:
    try:
        img = Image.open(img_path).convert('RGB')
    except Exception as e:
        print(f"Error opening image: {e}")
        exit(1)

# Resize to 128x160 (KMBox specific resolution)
img = img.resize((128, 160), Image.Resampling.LANCZOS)
width, height = img.size

data = []
for y in range(height):
    for x in range(width):
        r, g, b = img.getpixel((x, y))
        val = rgb888_to_rgb565(r, g, b)
        # Little Endian (Low byte first)
        data.append(val & 0xFF)
        data.append((val >> 8) & 0xFF)

try:
    with open(header_path, 'w') as f:
        f.write('#pragma once\n\n')
        f.write('// Auto-generated from dma.png\n')
        f.write('// 128x160 RGB565 format\n')
        f.write(f'unsigned char g_dma_pic[{len(data)}] = {{\n')
        
        for i in range(0, len(data), 16):
            chunk = data[i:i+16]
            hex_str = ', '.join([f'0x{b:02X}' for b in chunk])
            f.write(f'    {hex_str},\n')
            
        f.write('};\n')
    print(f"Successfully generated {header_path}")
except Exception as e:
    print(f"Error writing header file: {e}")
