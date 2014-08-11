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

void ResourcesLoader::loadResources()
{
    if (!_textureCache)
    {
        _textureCache = Director::getInstance()->getTextureCache();
    }

    this->loadImage("Playground");
    this->loadImage("Ball");
    this->loadImage("Door");
}

void ResourcesLoader::loadImage(string key){
    auto texture = _textureCache->addImage("Images/" + key + ".png");
        
    if (texture != nullptr)
    {
        _textureMap.insert(key, texture);
    }
}

Texture2D* ResourcesLoader::getTexture(string key)
{
    return _textureMap.at(key);
}



