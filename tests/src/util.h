#pragma once

#include <cstdint>
#include <filesystem>
#include <vector>
#include <blahdio/audio_data_format.h>
#include <blahdio/audio_type.h>

namespace util {

extern void compare_frames(const float* const a, const float* const b, std::uint64_t num_frames, int num_channels, float tolerance = 0.000001f);

extern void write_frames(
		const std::filesystem::path& file_path,
		const float* buffer,
		blahdio::AudioType audio_type,
		blahdio::AudioDataFormat format,
		int chunk_size = 512);

extern void read_frames(
		const std::filesystem::path& file_path,
		float* buffer,
		blahdio::AudioType audio_type_expected,
		blahdio::AudioDataFormat format_expected,
		int chunk_size = 512);

extern void write_read_compare(
		const float* data,
		blahdio::AudioType type,
		blahdio::AudioDataFormat format,
		int chunk_size = 512);

extern std::string to_string(blahdio::AudioType audio_type);
extern std::string get_ext(blahdio::AudioType audio_type);

extern std::vector<float> generate_sine_data(int num_frames, int num_channels, float frequency, int sample_rate = 44100);
extern std::vector<float> generate_noise_data(int num_frames, int num_channels);

} // util
