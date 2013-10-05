// settings.h

/////////////////////// remove warnings
#pragma warning(disable:4244)
#pragma warning(disable:4305)
#pragma warning(disable:4996)
#pragma warning(disable:4018)
#pragma warning(disable:4101)
#pragma warning(disable:4800)

#define SAFE_RELEASE(x) { if (x) { x->Release();  x = NULL; } }
// set up include and library paths

// paths for Decatur 6105 - replace with your specific DirectX path
//#define DXIncludePath C:/Program Files/Microsoft DirectX SDK (August 2009)/Include
//#define DXLibraryPath "C:/Program Files/Microsoft DirectX SDK (August 2009)/lib/x86/"
#define DXIncludePath C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include
#define DXLibraryPath "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/lib/x86/"
//#define FMODIncludePath C:/Program Files (x86)/FMOD SoundSystem/FMOD Programmers API Windows/api/inc
//#define FMODLibraryPath "C:/Program Files (x86)/FMOD SoundSystem/FMOD Programmers API Windows/api/lib/"


#define MakePath(a, b) <a/b>



/////////////////////////// libs
#pragma comment (lib, DXLibraryPath "d3d9.lib")
#pragma comment (lib, DXLibraryPath "d3dx9.lib")
#pragma comment (lib, DXLibraryPath "dxerr.lib")
#pragma comment (lib, DXLibraryPath "dxguid.lib")
#pragma comment (lib, DXLibraryPath "dsound.lib")
//#pragma comment (lib, FMODLibraryPath "fmodex_vc.lib")
#pragma comment (lib, "winmm.lib")

#pragma comment (lib, "Strmiids.lib")
#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

///////////////////////// don't use unicode - don't have to change project charset property :)
#undef UNICODE
#undef _UNICODE

