module;
#include <imgui.h>

export module render;
import std;
import dx11;

export class render {
public:

	static void DrawHealthBar(ImDrawList* drawList, ImVec2 center, float width, float height, int health, int maxHealth = 100, int style = 0);

    static void AddTextWithBackground(ImDrawList* drawList, const ImVec2& center, ImU32 textColor, const char* text);

	static void AddText(ImDrawList* drawList, const ImVec2& center, ImU32 textColor, const char* text, float fontSize = 0.0f);

	static void DrawCornerBox(ImDrawList* drawList, ImVec2 pos, float width, float height, ImU32 color, float thickness = 1.0f);
};

void render::DrawCornerBox(ImDrawList* drawList, ImVec2 pos, float width, float height, ImU32 color, float thickness)
{
	float lineW = width / 4.0f;
	float lineH = height / 4.0f;

	// Top Left
	drawList->AddLine(pos, { pos.x + lineW, pos.y }, color, thickness);
	drawList->AddLine(pos, { pos.x, pos.y + lineH }, color, thickness);

	// Top Right
	drawList->AddLine({ pos.x + width, pos.y }, { pos.x + width - lineW, pos.y }, color, thickness);
	drawList->AddLine({ pos.x + width, pos.y }, { pos.x + width, pos.y + lineH }, color, thickness);

	// Bottom Left
	drawList->AddLine({ pos.x, pos.y + height }, { pos.x + lineW, pos.y + height }, color, thickness);
	drawList->AddLine({ pos.x, pos.y + height }, { pos.x, pos.y + height - lineH }, color, thickness);

	// Bottom Right
	drawList->AddLine({ pos.x + width, pos.y + height }, { pos.x + width - lineW, pos.y + height }, color, thickness);
	drawList->AddLine({ pos.x + width, pos.y + height }, { pos.x + width, pos.y + height - lineH }, color, thickness);
}

void render::AddText(ImDrawList* drawList, const ImVec2& center, ImU32 textColor, const char* text, float fontSize)
{
    if (!text || !drawList) return;

    ImFont* font = ImGui::GetFont();
    float final_size = (fontSize > 0.0f) ? fontSize : ImGui::GetFontSize();

    // Use CalcTextSizeA for custom size
    ImVec2 text_size = font->CalcTextSizeA(final_size, FLT_MAX, 0.0f, text);
    ImVec2 text_pos(center.x - text_size.x * 0.5f, center.y);

    // Draw text with a simple shadow/outline for readability without a full box
    drawList->AddText(font, final_size, ImVec2(text_pos.x + 1, text_pos.y + 1), IM_COL32(0, 0, 0, 255), text);
    drawList->AddText(font, final_size, text_pos, textColor, text);
}

void render::DrawHealthBar(ImDrawList* drawList, ImVec2 center, float width, float height, int health, int maxHealth, int style)
{

    if (!drawList) return;

    float ratio = std::clamp((float)health / (float)maxHealth, 0.0f, 1.0f);

    ImU32 bgColor = IM_COL32(60, 60, 60, 200);  // 背景灰
    ImU32 borderColor = IM_COL32(0, 0, 0, 255);     // 黑边框

    // 计算矩形范围（中心对齐）
    ImVec2 minPos(center.x - width * 0.5f, center.y);
    ImVec2 maxPos(center.x + width * 0.5f, center.y + height);

    // 背景和边框
    drawList->AddRectFilled(minPos, maxPos, bgColor, 0.0f);

    ImVec2 hp_max(minPos.x + width * ratio, maxPos.y);

    if (style == 0) {
        // 样式 0：渐变 (整条血条呈现红黄绿渐变过渡)
        // 使用 MultiColor 绘制渐变矩形
        ImU32 colLeft = IM_COL32(255, 0, 0, 255);   // 红
        ImU32 colMid = IM_COL32(255, 255, 0, 255);  // 黄
        ImU32 colRight = IM_COL32(0, 255, 0, 255);  // 绿

        if (ratio > 0.0f) {
            if (ratio <= 0.5f) {
                // 只绘制左半部分（红到黄的过渡）
                float sub_ratio = ratio / 0.5f;
                // 计算当前位置的颜色插值
                int r = 255;
                int g = (int)(255 * sub_ratio);
                int b = 0;
                ImU32 curCol = IM_COL32(r, g, b, 255);
                drawList->AddRectFilledMultiColor(minPos, hp_max, colLeft, curCol, curCol, colLeft);
            } else {
                // 绘制左半部分（红到黄）
                ImVec2 midPos(minPos.x + width * 0.5f, maxPos.y);
                drawList->AddRectFilledMultiColor(minPos, midPos, colLeft, colMid, colMid, colLeft);
                
                // 绘制右半部分（黄到绿的过渡）
                float sub_ratio = (ratio - 0.5f) / 0.5f;
                int r = (int)(255 * (1.0f - sub_ratio));
                int g = 255;
                int b = 0;
                ImU32 curCol = IM_COL32(r, g, b, 255);
                drawList->AddRectFilledMultiColor(ImVec2(midPos.x, minPos.y), hp_max, colMid, curCol, curCol, colMid);
            }
        }
    } 
    else if (style == 1) {
        // 样式 1：跟随血量渐变 (整体单一颜色，根据血量比例变化)
        ImColor hpColor;
        if (ratio > 0.5f)
            hpColor = ImColor::HSV((ratio - 0.5f) * 0.6f, 0.9f, 0.9f);  // 黄到绿
        else
            hpColor = ImColor::HSV(0.0f, 0.9f, ratio * 1.5f + 0.3f);           // 红到暗红/黄
        
        drawList->AddRectFilled(minPos, hp_max, hpColor, 0.0f);
    }
    else if (style == 2) {
        // 样式 2：科技风 (一格一格的)
        int num_blocks = 10; // 总格数
        float gap = 1.0f;    // 格子间隙
        float block_width = (width - gap * (num_blocks - 1)) / num_blocks;
        
        int active_blocks = (int)(ratio * num_blocks + 0.5f); // 四舍五入计算激活的格数
        
        for (int i = 0; i < active_blocks; i++) {
            float cur_x = minPos.x + i * (block_width + gap);
            ImVec2 bMin(cur_x, minPos.y);
            ImVec2 bMax(cur_x + block_width, maxPos.y);
            
            // 颜色也可以根据格子位置渐变，这里使用青色/科技蓝风格
            float b_ratio = (float)i / (num_blocks - 1);
            ImU32 blockCol = IM_COL32(0, (int)(150 + 105 * b_ratio), 255, 255); 
            
            drawList->AddRectFilled(bMin, bMax, blockCol, 0.0f);
        }
    }

    // 边框
    drawList->AddRect(minPos, maxPos, borderColor, 0.0f);
}

void render::AddTextWithBackground(ImDrawList* drawList, const ImVec2& center, ImU32 textColor, const char* text)
{

    if (!text || !drawList) return;

    // 文字尺寸
    ImVec2 text_size = ImGui::CalcTextSize(text);

    // 保证文字在传入的中心点居中
    ImVec2 text_pos(center.x - text_size.x * 0.5f, center.y);

    // 背景矩形 (加 padding)
    float padding = 3.0f;
    ImVec2 bg_min(text_pos.x - padding, text_pos.y - padding);
    ImVec2 bg_max(text_pos.x + text_size.x + padding, text_pos.y + text_size.y + padding);

    // 背景
    drawList->AddRectFilled(bg_min, bg_max, imguiColor::DarkGray150, 4.0f);

    // 文字
    drawList->AddText(text_pos, textColor, text);
}
