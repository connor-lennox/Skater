//
// Created by connor on 1/10/26.
//

#pragma once
#include "AudioStreamInstance.h"
#include "include/soloud_wav.h"

using SoLoud::Wav;

namespace Skater {
    class AudioStream {
    public:
        explicit AudioStream(Wav *source) : _source(source) {}
        ~AudioStream();

        [[nodiscard]] AudioStreamInstance *CreateInstance();

        [[nodiscard]] Wav &GetSource() const;
        [[nodiscard]] float GetLength() const;
    private:
        Wav *_source;
    };
}
