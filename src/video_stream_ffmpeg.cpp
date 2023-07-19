#include "video_stream_ffmpeg.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libswresample/swresample.h>
#include <libswscale/swscale.h>

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

Variant VideoStreamFFMPEGLoader::_load(const String &p_path, const String &p_original_path, bool p_use_sub_threads, int32_t p_cache_mode) const {
	Ref<FileAccess> f = FileAccess::open(p_path, FileAccess::READ);
	if (f.is_null()) {
		return Ref<Resource>();
	}

	Ref<VideoStreamFFMPEG> stream;
	stream.instantiate();
	stream->set_file(p_path);

	return stream;
}

PackedStringArray VideoStreamFFMPEGLoader::_get_recognized_extensions() const {
	PackedStringArray arr;
	arr.push_back("mp4");
	return arr;
}

bool VideoStreamFFMPEGLoader::_handles_type(const StringName &p_type) const {
	return p_type.to_lower() == "videostream";
}

String VideoStreamFFMPEGLoader::_get_resource_type(const String &p_path) const {
	String extension = p_path.get_extension().to_lower();
	if (extension == "mp4") {
		return "VideoStreamFFMPEG";
	}
	return "";
}