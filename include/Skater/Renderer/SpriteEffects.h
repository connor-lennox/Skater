//
// Created by connor on 1/31/26.
//

#pragma once

namespace Skater {
    struct SpriteEffects {
        bool FlipHorizontal;
        bool FlipVertical;

        static const SpriteEffects None;
    };

    inline const SpriteEffects SpriteEffects::None = SpriteEffects(false, false);
}
