module;
#include "vmmdll.h"
#include  <vector>;
export module dma;
import std;

export using ::VMMDLL_SCATTER_HANDLE;
export using ::VMM_HANDLE;
export using ::PVMMDLL_PROCESS_INFORMATION;
export using ::QWORD;
export using ::PVMMDLL_MAP_MODULEENTRY;
export using ::PVMMDLL_MAP_EAT;



export class dma
{
public:


    static bool IsValidPointer(const ULONG64 address);

    static BOOL init();

    static BOOL Close();

    static DWORD GetPidFromName(const char* gameName);

    static std::vector<DWORD> GetPidListFromName(std::string name);

    static BOOL InitPidGetFromName(const char* gameName);

    static BOOL Read(ULONG64 address, void* value, size_t size);

    static BOOL Read(ULONG64 address, DWORD dwPID, void* value, size_t size);

    static uint64_t FindSignature(const char* signature, uint64_t range_start, uint64_t range_end, int PID);

    static VMMDLL_SCATTER_HANDLE Scatter_Initialize();

    static void Scatter_CloseHandle(VMMDLL_SCATTER_HANDLE hs);

    static BOOL Scatter_PrepareEx(VMMDLL_SCATTER_HANDLE hs,ULONG64 address, void* value, size_t size);

    static BOOL Scatter_ExecuteRead(VMMDLL_SCATTER_HANDLE hs);

    static BOOL Write(ULONG64 address, void* value, size_t size);

    static ULONG64 ProcessGetModuleBaseU(const char* ModuleBaseName);

    static uint64_t GetPEBAddress();

    static BOOL ProcessGetInformationAll(_Out_ PVMMDLL_PROCESS_INFORMATION* ppProcessInformationAll, _Out_ PDWORD pcProcessInformation );

    static void MemFree(_Frees_ptr_opt_ PVOID pvMem);

    static BOOL Map_GetEATU( _In_ DWORD dwPID, _In_ LPCSTR  uszModuleName, _Out_ PVMMDLL_MAP_EAT * ppEatMap);
    

    template<typename T>
    static T Read(ULONG_PTR address);

    template<typename T>
    static T Read(ULONG_PTR address, DWORD dwPID);

    static VMM_HANDLE get_hVMM() { return hVMM; }

	static DWORD get_PID() { return m_pid; }

    static void Refresh_TLB();

    static void Refresh_MEM();

    static void Refresh_MEDIUM();
private:
    static inline VMM_HANDLE hVMM = NULL;
    static inline DWORD m_pid = 0;

    static uint8_t GetByte(const char* hex);

    static inline const char* hexdigits =
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\001\002\003\004\005\006\007\010\011\000\000\000\000\000\000"
        "\000\012\013\014\015\016\017\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\012\013\014\015\016\017\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
        "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000";
};

uint8_t dma::GetByte(const char* hex)
{
    return (uint8_t)((hexdigits[hex[0]] << 4) | (hexdigits[hex[1]]));
}

bool dma::IsValidPointer(const ULONG64 address) {
    return !( address <= 0x400000  || address == 0xCCCCCCCCCCCCCCCC || reinterpret_cast<void*>(address) == nullptr || address > 0x7FFFFFFFFFFFFFFF );
}

BOOL dma::init()
{
    VMMDLL_CloseAll();
    BOOL result = FALSE;
    const char* p[] = {
        "", "-norefresh",  "-device" , "fpga" 
    };//, 

    hVMM = VMMDLL_Initialize(4, p);

    if (!hVMM) {
        printf("VMMDLL_Initialize fall\n");
        return FALSE;
    }


    return TRUE;
}

BOOL dma::Close()
{
    VMMDLL_Close(hVMM);
    //VMMDLL_CloseAll();
    return FALSE;
}

DWORD dma::GetPidFromName(const char* gameName) {
    DWORD pid{};
    VMMDLL_PidGetFromName(hVMM, (LPCSTR)gameName, &pid);

    return pid;
}

std::vector<DWORD> dma::GetPidListFromName(std::string name)
{
    PVMMDLL_PROCESS_INFORMATION process_info = NULL;
    DWORD total_processes = 0;
    std::vector<DWORD> list = { };
    bool result = ProcessGetInformationAll( &process_info, &total_processes);

    if (!result)
    {
        printf("[!] Failed to get process list\n");
        return list;
    }

    for (size_t i = 0; i < total_processes; i++)
    {
        auto process = process_info[i];
        if (strstr(process.szNameLong, name.c_str()))
            list.push_back(process.dwPID);
    }

    VMMDLL_MemFree(process_info);

    return list;
}


BOOL dma::InitPidGetFromName(const char* gameName)
{
    
    VMMDLL_PidGetFromName(hVMM, (LPCSTR)gameName, &m_pid);
    if (!m_pid) {
        return FALSE;
    }

    return TRUE;
}

BOOL dma::Read(ULONG64 address, void* value, size_t size)
{
    if (!IsValidPointer(address) || !value || size == 0) {
        return FALSE;
    }

    DWORD bytesRead = 0;
    BOOL success = VMMDLL_MemReadEx(hVMM, m_pid, address, (PBYTE)value, size, &bytesRead, VMMDLL_FLAG_NOCACHE );
    return success;
}

BOOL dma::Read(ULONG64 address, DWORD dwPID ,void* value, size_t size)
{
    if (!IsValidPointer(address) || !value || size == 0) {
        return FALSE;
    }

    DWORD bytesRead = 0;
    BOOL success = VMMDLL_MemReadEx(hVMM, dwPID, address, (PBYTE)value, size, &bytesRead, VMMDLL_FLAG_NOCACHE );
    return success;
}

uint64_t dma::FindSignature(const char* signature, uint64_t range_start, uint64_t range_end, int PID)
{
    if (!signature || signature[0] == '\0' || range_start >= range_end)
        return 0;

    if (PID == 0)
        PID = m_pid;

    std::vector<uint8_t> buffer(range_end - range_start);
    if (!VMMDLL_MemReadEx(hVMM, PID, range_start, buffer.data(), buffer.size(), 0, VMMDLL_FLAG_NOCACHE | VMMDLL_FLAG_NOPAGING_IO))
        return 0;

    const char* pat = signature;
    uint64_t first_match = 0;
    for (uint64_t i = range_start; i < range_end; i++)
    {
        if (*pat == '?' || buffer[i - range_start] == GetByte(pat))
        {
            if (!first_match)
                first_match = i;

            if (!pat[2])
                break;

            pat += (*pat == '?') ? 2 : 3;
        }
        else
        {
            pat = signature;
            first_match = 0;
        }
    }

    return first_match;
}

VMMDLL_SCATTER_HANDLE dma::Scatter_Initialize()
{

    const auto flags = VMMDLL_FLAG_NOCACHE  | VMMDLL_FLAG_NOPAGING_IO;
    return VMMDLL_Scatter_Initialize(hVMM, m_pid, flags);
}

void dma::Scatter_CloseHandle(VMMDLL_SCATTER_HANDLE hs)
{
    VMMDLL_Scatter_CloseHandle (hs);
}



BOOL dma::Scatter_PrepareEx(VMMDLL_SCATTER_HANDLE hs , ULONG64 address, void* value, size_t size)
{

    if (!value || size == 0) {
        return FALSE;
    }
    return VMMDLL_Scatter_PrepareEx(hs, address, size, (PBYTE)value, NULL);
}

BOOL dma::Scatter_ExecuteRead(VMMDLL_SCATTER_HANDLE hs){

    BOOL success = VMMDLL_Scatter_ExecuteRead(hs);

    const auto flags = VMMDLL_FLAG_NOCACHE ;
	VMMDLL_Scatter_Clear(hs, m_pid, flags);
    return success;
}

BOOL dma::Write(ULONG64 address, void* value, size_t size)
{

    if (!value || size == 0) {
        return FALSE;
    }

    return VMMDLL_MemWrite(hVMM, m_pid, address, (PBYTE)value, size);
}


ULONG64 dma::ProcessGetModuleBaseU(const char* ModuleBaseName)
{
    return VMMDLL_ProcessGetModuleBaseU(hVMM, m_pid, (LPCSTR)ModuleBaseName);
}

uint64_t dma::GetPEBAddress() {



    VMMDLL_PROCESS_INFORMATION procInfo = { 0 };
    SIZE_T cbProcInfo = sizeof(VMMDLL_PROCESS_INFORMATION);

    procInfo.magic = VMMDLL_PROCESS_INFORMATION_MAGIC;
    procInfo.wVersion = VMMDLL_PROCESS_INFORMATION_VERSION;
    procInfo.wSize = (WORD)cbProcInfo;

    if (!VMMDLL_ProcessGetInformation(hVMM, m_pid, &procInfo, &cbProcInfo)) {
        return 0x0;
    }

    uint64_t PebAddress = procInfo.win.vaPEB;
    return PebAddress;
}

BOOL dma::ProcessGetInformationAll(PVMMDLL_PROCESS_INFORMATION* ppProcessInformationAll, PDWORD pcProcessInformation)
{
    
    return VMMDLL_ProcessGetInformationAll(hVMM, ppProcessInformationAll, pcProcessInformation);
}

void dma::MemFree(_Frees_ptr_opt_ PVOID pvMem)
{


    VMMDLL_MemFree(pvMem);
}

BOOL dma::Map_GetEATU(DWORD dwPID, LPCSTR uszModuleName, PVMMDLL_MAP_EAT* ppEatMap)
{
    return VMMDLL_Map_GetEATU(hVMM, dwPID, uszModuleName, ppEatMap);
}

void dma::Refresh_TLB()
{
    VMMDLL_ConfigSet(hVMM, VMMDLL_OPT_REFRESH_FREQ_TLB, 1);

}

void dma::Refresh_MEM()
{
    VMMDLL_ConfigSet(hVMM, VMMDLL_OPT_REFRESH_FREQ_MEM, 1);
}

void dma::Refresh_MEDIUM()
{
    VMMDLL_ConfigSet(hVMM, VMMDLL_OPT_REFRESH_ALL, 1);
}

template<typename T>
T dma::Read(ULONG_PTR address)
{
    T value{};
    if (!Read(address, &value, sizeof(T))) {
        return T{};
    }
    return value;
}
template<typename T>
T dma::Read(ULONG_PTR address , DWORD dwPID)
{
    T value{};
    if (!Read(address, dwPID, &value, sizeof(T))) {
        return T{};
    }
    return value;
}
