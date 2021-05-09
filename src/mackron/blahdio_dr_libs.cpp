#include "blahdio_dr_libs.h"
#include <utf8.h>

#define DR_FLAC_IMPLEMENTATION
#define DR_MP3_IMPLEMENTATION
#define DR_WAV_IMPLEMENTATION
#include <dr_flac.h>
#include <dr_mp3.h>
#include <dr_wav.h>

namespace blahdio {
namespace dr_libs {

namespace flac {

drflac* open_file(const std::string& utf8_path)
{
#ifdef _WIN32
	return drflac_open_file_w((const wchar_t*)(utf8::utf8to16(utf8_path).c_str()), nullptr);
#else
	return drflac_open_file(utf8_path.c_str(), nullptr);
#endif
}

} // flac

namespace mp3 {

bool init_file(drmp3* mp3, const std::string& utf8_path)
{
#ifdef _WIN32
	return drmp3_init_file_w(mp3, (const wchar_t*)(utf8::utf8to16(utf8_path).c_str()), nullptr);
#else
	return drmp3_init_file(mp3, utf8_path.c_str(), nullptr);
#endif
}

} // mp3

namespace wav {

bool init_file(drwav* wav, const std::string& utf8_path)
{
#ifdef _WIN32
	return drwav_init_file_w(wav, (const wchar_t*)(utf8::utf8to16(utf8_path).c_str()), nullptr);
#else
	return drwav_init_file(wav, utf8_path.c_str(), nullptr);
#endif
}

bool init_file_write(drwav* wav, const std::string& utf8_path, const drwav_data_format* format)
{
#ifdef _WIN32
	return drwav_init_file_write_w(wav, (const wchar_t*)(utf8::utf8to16(utf8_path).c_str()), format, nullptr);
#else
	return drwav_init_file_write(wav, utf8_path.c_str(), format, nullptr);
#endif
}

} // wav

}
}