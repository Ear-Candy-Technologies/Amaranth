# Developer Guide

## Introduction

This ReadMe contains all the rules and guidelines necessary for development and input within Amaranth. All the points below are based on C++ best practices and the [JUCE coding standards](https://juce.com/discover/stories/coding-standards) (we recommend taking these writing practices as the main basis for the development in Amaranth).

## Contributions

### Code reviews

At the time of making a Pull Request, your code will always be reviewed by the Ear Candy Technologies team in order to guarantee that there is no problem with the main project or that it has poorly implemented code. If it is necessary to make any changes, the person will be notified through the Pull Request with the corresponding comments. Taking all these rules into account can make response times more efficient.

### Using GitHub

#### If you are not familiar with the use of GitHub, we have prepared a video on YouTube to make it a little easier for you: https://youtu.be/oAkASvtDke0

1. The developer must create a fork from the main project to have a copy of the repository in his profile.
2. Next, clone the repository fork `git clone https://github.com/your-user-name/Amaranth.git`
3. Subsequently, a branch from *develop* must be opened with the name presented in the [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd). If you are going to work on an existing branch you will have to open another one from that one.
4. Make the commits and push corresponding to the changes you implemented.
5. At the end of your implementation, make the Pull Request to the original project and share it's link on Discord so that it can be reviewed. If all is well, it will be accepted and the merge will be done.
6. If you have spent a long time on a single issue, it is recommended to do `git rebase` with *develop* so that conflicts do not occur at the time of the Pull Request.
7. In order to synchronize the current changes from the original repository with your fork you must add an upstream with the following command `git remote add upstream https://github.com/Ear-Candy-Technologies/Amaranth.git`
8. To perform the corresponding pulls and obtain the current state of the parent repository the following command is more than enough: `git pull upstream develop` (always remember to update the develop branch).
9. The issues proposed both in the Scrum Board and in GitHub are proposed by the Ear Candy Technologies team, however, we are totally open to new features and development proposals. For this, it is necessary to send a message notifying the ECT team and for the proposal to be accepted.

### How to start my development?

1. If a new class is going to be added, it must be divided into .h and .cpp files
2. New files should always go in the corresponding folders of DSP, GUI, Utilities, etc. depending on its functionality.
3. Any parameter that has to be added to the AudioProcessorValueTreeState, both the name and the ID, must be declared in the ParamsHelper.h file and follow the structure of the previously created parameters.
4. When creating a new class, briefly comment in the .h file explaining what each declared method, function and/or variable is for (reference the *Oscillator* class for this).
5. Any doubt about the development and/or structure of the project please ask on Discord.

Note: For Windows users who use the copy step of the projucer, take into account not to upload the path you use on your personal computer to avoid future problems.

### Commit messages

The commits must be composed of

```
<short description of the changes made in the commit in a single line>
```

### Bug Report

To report a bug that you have found and that you would like to expose so that it can be resolved by you or by the community, go to the *Issues* section and click on the *New Issue* option, there you will find the template. *Bug report* where you must describe the bug as requested.
