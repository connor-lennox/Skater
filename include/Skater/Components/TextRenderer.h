//
// Created by connor on 1/9/26.
//

#pragma once
#include "GraphicsComponent.h"
#include "Skater/Text/Font.h"

using namespace std;

namespace Skater {
    class TextRenderer final : public GraphicsComponent {
    public:
        TextRenderer() : TextRenderer(nullptr) {}
        explicit TextRenderer(Font *font) : TextRenderer(font, "") {}
        TextRenderer(Font *font, const string &text) : GraphicsComponent("TextRenderer"), _font(font), _text(text) {}

        void Render() override;

        void SetFont(Font *font) { _font = font; }
        void SetText(const string &text) { _text = text; }
    private:
        Font *_font;
        string _text;
    };
}
