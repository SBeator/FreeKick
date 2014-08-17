#include "ResourcesLoader.h"

USING_NS_CC;
using namespace std;

ResourcesLoader::ResourcesLoader(){}

ResourcesLoader* ResourcesLoader::_resourcesLoader;
TextureCache* ResourcesLoader::_textureCache;

ResourcesLoader* ResourcesLoader::getInstance()
{
    if (!_resourcesLoader)
    {
        _resourcesLoader = new ResourcesLoader();
    }
    
    return _resourcesLoader;
}

Texture2D* ResourcesLoader::getWelcomePage()
{
    if (!_textureCache)
    {
        _textureCache = Director::getInstance()->getTextureCache();
    }

    auto page = this->loadImage("WelcomePage");
    return page;
}

void ResourcesLoader::loadResources()
{
    if (!_textureCache)
    {
        _textureCache = Director::getInstance()->getTextureCache();
    }

    this->loadImage("Playground");
    this->loadImage("Ball");
    this->loadImage("Door");
    this->loadImage("Player");

    this->loadImage("Goal");
    this->loadImage("Fail");
    this->loadImage("Reset");
    this->loadImage("ResetPressed");
}

Texture2D* ResourcesLoader::loadImage(string key){
    auto texture = _textureCache->addImage("Images/" + key + ".png");
        
    if (texture != nullptr)
    {
        _textureMap.insert(key, texture);
    }

    return texture;
}

Texture2D* ResourcesLoader::getTexture(string key)
{
    return _textureMap.at(key);
}



