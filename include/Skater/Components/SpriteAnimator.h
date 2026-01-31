//
// Created by connor on 1/31/26.
//

#pragma once
#include <cstdint>
#include <unordered_map>
#include <vector>

#include "SpriteRenderer.h"
#include "Skater/Core/Component.h"

namespace Skater {
    struct SpriteAnimation {
        std::vector<uint32_t> Frames;
        float FrameTime;

        [[nodiscard]] uint32_t Length() const { return Frames.size(); }
    };

    enum class SpriteLoopMode {
        Stop,
        Loop
    };

    class SpriteAnimator final : public Component {
    public:
        explicit SpriteAnimator(SpriteRenderer *renderer);
        void Update() override;

        void AddAnimation(const std::string &identifier, std::vector<uint32_t> frames, float frameTime = 0);
        void AddLinearAnimation(const std::string &identifier, uint32_t start, uint32_t end, float frameTime = 0);

        void Play(const std::string &identifier);

        void SetLoopMode(SpriteLoopMode mode);
        void SetDefaultFrameTime(float defaultFrameTime);
    private:
        void ProgressFrame();

        SpriteRenderer *_renderer;

        std::unordered_map<std::string, SpriteAnimation> _animations;
        SpriteAnimation *_currentAnimation = nullptr;

        float _frameTimer = 0;
        uint32_t _currentFrame = 0;
        SpriteLoopMode _loopMode = SpriteLoopMode::Stop;

        float _defaultFrameTime = 1;
    };
}
