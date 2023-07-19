#ifndef VIDEO_STREAM_FFMPEG_H
#define VIDEO_STREAM_FFMPEG_H

#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/resource_format_loader.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/video_stream_playback.hpp>
#include <godot_cpp/classes/video_stream.hpp>
#include <godot_cpp/classes/texture2d.hpp>

namespace godot {

class VideoStreamPlaybackFFMPEG : public VideoStreamPlayback {
	GDCLASS(VideoStreamPlaybackFFMPEG, VideoStreamPlayback);

protected:
	static void _bind_methods();

public:
	virtual void _play() override;
	virtual void _stop() override;
	virtual bool _is_playing() const override;

	virtual void _set_paused(bool p_paused) override;
	virtual bool _is_paused() const override;

	virtual double _get_length() const override;

	virtual double _get_playback_position() const override;
	virtual void _seek(double p_time) override;

	void _set_file(const String &p_file);

	virtual Ref<Texture2D> _get_texture() const override;
	virtual void _update(double p_delta) override;

	virtual int _get_channels() const override;
	virtual int _get_mix_rate() const override;

	virtual void _set_audio_track(int p_idx) override;

	VideoStreamPlaybackFFMPEG();
	~VideoStreamPlaybackFFMPEG();
};

class VideoStreamFFMPEG : public VideoStream {
	GDCLASS(VideoStreamFFMPEG, VideoStream);

	String file;
	int audio_track = 0;

protected:
	static void _bind_methods();

public:
	Ref<VideoStreamPlayback> _instantiate_playback() override {
		Ref<VideoStreamPlaybackFFMPEG> pb = memnew(VideoStreamPlaybackFFMPEG);
		pb->_set_audio_track(audio_track);
		pb->_set_file(file);
		return pb;
	}

	VideoStreamFFMPEG() {}
	~VideoStreamFFMPEG() {}
};

class VideoStreamFFMPEGLoader : public ResourceFormatLoader {
	GDCLASS(VideoStreamFFMPEGLoader, ResourceFormatLoader);

protected:
	static void _bind_methods() {};

public:
	virtual Variant _load(const String &p_path, const String &p_original_path, bool p_use_sub_threads, int32_t p_cache_mode = CACHE_MODE_REUSE) const override;
	virtual PackedStringArray _get_recognized_extensions() const override;
	virtual bool _handles_type(const StringName &p_type) const override;
	virtual String _get_resource_type(const String &p_path) const override;

	VideoStreamFFMPEGLoader() {}
	~VideoStreamFFMPEGLoader() {}
};

} // namespace godot

#endif // VIDEO_STREAM_FFMPEG_H