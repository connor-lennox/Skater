//
// Created by connor on 1/10/26.
//

#include "Skater/Components/AudioStreamPlayer.h"

namespace Skater {
    AudioStreamPlayer::AudioStreamPlayer() : Component("AudioStreamPlayer") {}

    AudioStreamPlayer::~AudioStreamPlayer() {
        _audioInstance.Stop();
    }

    void AudioStreamPlayer::SetAudioStream(AudioStream *audioStream) {
        _audioInstance.SetStream(audioStream);
    }

    void AudioStreamPlayer::Play() {
        _audioInstance.Play();
    }

    void AudioStreamPlayer::Stop() {
        _audioInstance.Stop();
    }
}
