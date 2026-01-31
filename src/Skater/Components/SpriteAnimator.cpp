//
// Created by connor on 1/31/26.
//

#include "Skater/Components/SpriteAnimator.h"

#include <numeric>
#include <utility>

#include "Skater/Core/Time.h"

namespace Skater {
    SpriteAnimator::SpriteAnimator(SpriteRenderer *renderer) : Component("SpriteAnimator"), _renderer(renderer) {}

    void SpriteAnimator::Update() {
        if (_currentAnimation == nullptr) {
            return;
        }

        _frameTimer -= Time::DeltaTime();
        if (_frameTimer <= 0) {
            ProgressFrame();
        }
    }

    void SpriteAnimator::ProgressFrame() {
        _frameTimer = _currentAnimation->FrameTime;

        if (_currentFrame == _currentAnimation->Length() - 1) {
            if (_loopMode == SpriteLoopMode::Stop) {
                return;
            }

            _currentFrame = 0;
            _renderer->Frame = _currentAnimation->Frames[_currentFrame];
            return;
        }

        _currentFrame += 1;
        _renderer->Frame = _currentAnimation->Frames[_currentFrame];
    }

    void SpriteAnimator::AddAnimation(const std::string &identifier, std::vector<uint32_t> frames, const float frameTime) {
        _animations[identifier] = SpriteAnimation(std::move(frames), frameTime != 0 ? frameTime : _defaultFrameTime);
    }

    void SpriteAnimator::AddLinearAnimation(const std::string &identifier, const uint32_t start, const uint32_t end, const float frameTime) {
        auto s = start;
        auto e = end;
        if (e < s) {
            s = end;
            e = start;
        }
        auto v = std::vector<uint32_t>(e - s + 1);
        std::iota(v.begin(), v.end(), s);

        _animations[identifier] = SpriteAnimation(std::move(v), frameTime != 0 ? frameTime : _defaultFrameTime);
    }

    void SpriteAnimator::Play(const std::string &identifier) {
        _currentAnimation = &_animations[identifier];
        _currentFrame = 0;
        _frameTimer = _currentAnimation->FrameTime;
        _renderer->Frame = _currentAnimation->Frames[0];
    }

    void SpriteAnimator::SetLoopMode(const SpriteLoopMode mode) {
        _loopMode = mode;
    }

    void SpriteAnimator::SetDefaultFrameTime(const float defaultFrameTime) {
        _defaultFrameTime = defaultFrameTime;
    }
}
