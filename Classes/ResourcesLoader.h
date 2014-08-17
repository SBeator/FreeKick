#pragma once

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class ResourcesLoader
{
public:
    static ResourcesLoader* getInstance();

    Texture2D* getWelcomePage();
    void loadResources();
    Texture2D* getTexture(string key);

private:
    static ResourcesLoader* _resourcesLoader;

    static TextureCache* _textureCache;

    ResourcesLoader();
    Texture2D* loadImage(string key);

    Map<string, Texture2D*> _textureMap;
};

