#pragma once

#include <map>
#include "PaletteStamper.h"
#include "Rect2.h"

class PaletteImageStamper : public PaletteStamper {
    PaletteImage _image;
    SDL_Renderer* _renderer;
    std::map<const Palette<Color4>*, SDL_Texture*> _textures;

    PaletteImageStamper(const PaletteImageStamper& rhs);
    PaletteImageStamper& operator=(const PaletteImageStamper& rhs);
    PaletteImageStamper& operator=(PaletteImageStamper&& rhs);

    SDL_Texture* createTexture(const Palette<Color4>& palette) const;
public:
    PaletteImageStamper(PaletteImage&& image, Palette<Color4>* defaultPalette = nullptr);
    PaletteImageStamper(SDL_Renderer* renderer, PaletteImage&& image, Palette<Color4>* defaultPalette = nullptr);
    PaletteImageStamper(PaletteImageStamper&& rhs);
    ~PaletteImageStamper();

    void draw(const Palette<Color4>& palette, Image4& screen, const Rect2<double>& bounds);
    void draw(const Palette<Color4>& palette, SDL_Renderer* renderer, const Rect2<double>& bounds);
    void draw(Image4& screen, const Rect2<double>& bounds);
    void draw(SDL_Renderer* renderer, const Rect2<double>& bounds);
};

