#pragma once
#include <string>
#include "sl.h"
#include "CCDSize.h"
#define STB_IMAGE_IMPLEMENTATION
#include "libs\stb_image.h"

namespace cascade {
	class Texture {
	protected:
		int texture;
		std::string filepath;
		Size size;
		bool textureLoaded;
	public:
		Texture(std::string filename) {
			texture = slLoadTexture(filename.c_str());
			filepath = filename;

			int x, y, n, supportedFormat;
			supportedFormat = stbi_info(filename.c_str(), &x, &y, &n);

			textureLoaded = supportedFormat;

			if (supportedFormat) {
				// ok
				size = Size(x, y);
			}
			else {
				// error
			}
		}
		int getTexture() { return texture; }
		std::string getFilepath() { return filepath; }
		bool isLoaded() { return textureLoaded; }
		Size getSize() { return size; }
	};
}