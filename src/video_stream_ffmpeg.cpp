#include "video_stream_ffmpeg.h"

using namespace godot;

void VideoStreamPlaybackFFMPEG::_bind_methods()
{

}

void VideoStreamPlaybackFFMPEG::_play() {
}

void VideoStreamPlaybackFFMPEG::_stop() {
}

bool VideoStreamPlaybackFFMPEG::_is_playing() const {
	return false;
}

void VideoStreamPlaybackFFMPEG::_set_paused(bool p_paused) {
}

bool VideoStreamPlaybackFFMPEG::_is_paused() const {
	return false;
}

double VideoStreamPlaybackFFMPEG::_get_length() const {
	return 0;
}

double VideoStreamPlaybackFFMPEG::_get_playback_position() const {
	return 0;
}

void VideoStreamPlaybackFFMPEG::_seek(double p_time) {
}

void VideoStreamPlaybackFFMPEG::_set_file(const String &p_file) {
}

Ref<Texture2D> VideoStreamPlaybackFFMPEG::_get_texture() const {
	return nullptr;
}

void VideoStreamPlaybackFFMPEG::_update(double p_delta) {
}

int VideoStreamPlaybackFFMPEG::_get_channels() const {
	return 0;
}

int VideoStreamPlaybackFFMPEG::_get_mix_rate() const {
	return 0;
}

void VideoStreamPlaybackFFMPEG::_set_audio_track(int p_idx) {
}

VideoStreamPlaybackFFMPEG::VideoStreamPlaybackFFMPEG() {
}

VideoStreamPlaybackFFMPEG::~VideoStreamPlaybackFFMPEG() {
};

void VideoStreamFFMPEG::_bind_methods() {}

Ref<Resource> ResourceFormatLoaderFFMPEG::_load(const String &p_path, const String &p_original_path, Error *r_error, bool p_use_sub_threads, float *r_progress, CacheMode p_cache_mode) {
	return nullptr;
}

void ResourceFormatLoaderFFMPEG::_get_recognized_extensions(List<String> *p_extensions) const {
}

bool ResourceFormatLoaderFFMPEG::_handles_type(const String &p_type) const {
	return false;
}

String ResourceFormatLoaderFFMPEG::_get_resource_type(const String &p_path) const {
	return "";
}