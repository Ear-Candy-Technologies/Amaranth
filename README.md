# Amaranth

Amaranth is a free and open-source synthesizer developed in JUCE by the [Ear Candy Technologies](https://earcandytech.com/) community with the aim of promoting technological development in Latin America and mainly the Spanish-speaking community. Anyone is free to download this project and/or help in its development. If you want to enter the development community to ask any questions or just to connect with us, we are on [Discord](https://discord.gg/fMhnNaxS8). This ReadMe is intended to be the path for Amaranth's contribution or download.

### Fun Fact: The name Amaranth comes from joining *Amaranto* (mexican candy) with the word *Synth*.

## Dependencies

### JUCE

You can download JUCE from the official website https://juce.com/ and follow the tutorials to install it or watch our Youtube video where it is explained in more detail for both MacOs and Windows https://www.youtube.com/watch?v=bdYi-UdHd5g&t=449s

## How to compile?

1. Xcode (MacOs): just download from App Store https://apps.apple.com/us/app/xcode/id497799835?mt=12
2. Visual Studio (Windows): You can download it from the official website https://visualstudio.microsoft.com/es/ (remember to download the C++ tools when configuring the installer).
3. Download JUCE.
3. Clone this repository [How to clone section](#How-to-clone).
4. The project is executed by the projucer so simply by double clicking the file `Amaranth.jucer` you'll be able to access to it. 
5. Select your IDE based on your operating system and open the project in it.
6. Have fun and help us!

## Developing
## How-to-clone

HTTPS
```
git clone --recurse-submodules https://github.com/Ear-Candy-Technologies/Amaranth.git
```

SSH
```
git clone --recurse-submodules git@github.com:Ear-Candy-Technologies/Amaranth.git
```

If already cloned without `--recurse-submodule`

```bash
cd Amaranth
git submodule update --init --recursive
```
In the next document you will find the guidelines to start contribuiting to Amaranth Synth.

[Developer Guide](https://github.com/Ear-Candy-Technologies/Amaranth/blob/main/DeveloperGuide.md) (read before you start developing)
