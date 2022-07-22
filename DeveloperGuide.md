# Developer Guide

# Español

## Introducción

Este ReadMe contiene todas las normas y guias necesarias para el desarrollo y aportación dentro de Amaranth. Todos los puntos a continuación estan basados en buenas prácticas de C++ y los [estándares de código de JUCE](https://juce.com/discover/stories/coding-standards) (recomendamos tomar estás prácticas de escritura como base principal para el desarrollo en Amaranth). 

Si tienes alguna pregunta que no esté aclarada en este ReadMe puedes resolverla en la comunidad de Ear Candy Technologies de [Discord](https://discord.gg/WJvn7m2KwJ) dentro del canal de #Amaranth.

## Contribuciones

### Revisiones de código

Al momento de hacer un Pull Request siempre se hará una revisión de tu código por parte del equipo de Ear Candy Technologies con el fin de garantizar que no haya ningún problema con el proyecto principal ni que tenga código mal implementado. Si es necesario hacer algún cambio se notificará a la persona a través del Pull Request con los comentarios correspondientes. Tomar en cuenta todas estas normas pueden eficientar los tiempos de respuesta.

### Uso de GitHub

#### Si no estas familiarizado con el uso de GitHub preparamos un video en YouTube para facilitarte un poco el uso de esta herramienta: https://youtu.be/oAkASvtDke0

1. Se va a tener un [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd) donde estarán todos los issues y bugs actuales del proyecto, debes elegir algún issue o bug de la columna de backlog, colocar tu usuario de github, el nombre del branch que vas a crear y pasarlo a la columna de "En proceso".
2. Estos issues tambien van a estar presentes en el repositorio de GitHub.
3. El desarrollador debe de crear un fork desde el proyecto principal para tener un copia del repositorio en su perfil.
4. A continuación se debe de clonar el fork del repositorio `git clone https://github.com/your-user-name/Amaranth.git`
5. Posteriormente se debe de abrir una branch que salga de *develop* con el nombre presentado en el [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd). Si vas a trabajar en una branch ya existente deberás de abrir otra a partir de esa.
6. Realiza los commits y push correspondientes a los cambios que implementaste. 
7. Al terminar tu implementación realiza el Pull Request al proyecto original y comparte el link del mismo en Discord para que sea revisado. Si todo está bien, se aceptará y se hará merge.
8. Si llevas mucho tiempo en un solo issue es recomendable hacer `git rebase` con *develop* para que no sucedan conflictos al momento del Pull Request.
9. Para poder sincronizar los cambios actuales del reposirotio original con tu fork debes de añadir un upstream con el siguiente comando `git remote add upstream https://github.com/Ear-Candy-Technologies/Amaranth.git`
10. Para realizar los correspondientes pulls y obtener el estado actual del repositorio padre con realizar un pull de la siguiente forma es más que suficiente: `git pull upstream develop` (recuerda siempre actualizar la rama de develop).
11. Los issues propuestos tanto en el Scrum Board como en GitHub son propuestas por el equipo de Ear Candy Technologies, sin embargo, estamos totalmente abiertos a nuevos features y propuestas de desarrollo. Para esto, es necesario mandar mensaje notificando al equipo de ECT y que se acepte la propuesta.

### ¿Cómo empezar mi desarrollo?

1. Si se va a añadir una clase nueva debe estar dividio en archivos .h y .cpp
2. Los archivos nuevos siempre deben de ir en las carpetas correspondientes de DSP, GUI, Utilities, etc. según sea su funcionalidad.
3. Cualquier parámetro que se tenga que añadir al AudioProcessorValueTreeState, tanto el nombre como el ID, se deben de declarar en el archivo ParamsHelper.h y seguir la estructura de los parámetros previamente creados.
4. Al momento de crear una nueva clase se debe de comentar brevemente en el archivo .h explicando para qué es cada método, función y/o variable declarada (tomar de referencia la clase de *Oscilador* para esto).
5. Cualquier duda de desarrollo y/o de estructura del proyecto favor de preguntar en Discord.

Nota: Para los usuarios de Windows que utilicen el copy step del projucer tomar en cuenta de no subir el path que utilizan en su computadora personal para evitar futuros problemas.

### Mensajes de commits

Los commits deben estar compuestos de

```
<descripción breve de los cambios hechos en el commit en una sola linea>
```

### Reporte de Bugs

Para realizar el reporte de algún bug que hayas encontrado y que quisieras exponer para que sea resuelto por ti o por la comunidad, dirígete a la sección de *Issues* y da click en la opción de *New Issue*, ahí encontrarás la plantilla de *Reporte de bug* dónde deberás de describir el bug como se pide.

# English

## Introduction

This ReadMe contains all the rules and guidelines necessary for development and input within Amaranth. All the points below are based on C++ best practices and the [JUCE coding standards](https://juce.com/discover/stories/coding-standards) (we recommend taking these writing practices as the main basis for the development in Amaranth).

If you have any questions that are not clarified in this ReadMe, you can solve them in the Ear Candy Technologies community of [Discord](https://discord.gg/WJvn7m2KwJ) within the #Amaranth channel.

## Contributions

### Code reviews

At the time of making a Pull Request, your code will always be reviewed by the Ear Candy Technologies team in order to guarantee that there is no problem with the main project or that it has poorly implemented code. If it is necessary to make any changes, the person will be notified through the Pull Request with the corresponding comments. Taking all these rules into account can make response times more efficient.

### Using GitHub

#### If you are not familiar with the use of GitHub, we have prepared a video on YouTube to make it a little easier for you: https://youtu.be/oAkASvtDke0

1. There is going to be a [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd) where all the current issues and bugs of the project will be, you must choose an issue or bug from the backlog column, put your github user, the name of the branch you are going to create and pass it to the "In process" column.
2. These issues will also be present in the GitHub repository.
3. The developer must create a fork from the main project to have a copy of the repository in his profile.
4. Next, clone the repository fork `git clone https://github.com/your-user-name/Amaranth.git`
5. Subsequently, a branch from *develop* must be opened with the name presented in the [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd). If you are going to work on an existing branch you will have to open another one from that one.
6. Make the commits and push corresponding to the changes you implemented.
7. At the end of your implementation, make the Pull Request to the original project and share it's link on Discord so that it can be reviewed. If all is well, it will be accepted and the merge will be done.
8. If you have spent a long time on a single issue, it is recommended to do `git rebase` with *develop* so that conflicts do not occur at the time of the Pull Request.
9. In order to synchronize the current changes from the original repository with your fork you must add an upstream with the following command `git remote add upstream https://github.com/Ear-Candy-Technologies/Amaranth.git`
10. To perform the corresponding pulls and obtain the current state of the parent repository the following command is more than enough: `git pull upstream develop` (always remember to update the develop branch).
11. The issues proposed both in the Scrum Board and in GitHub are proposed by the Ear Candy Technologies team, however, we are totally open to new features and development proposals. For this, it is necessary to send a message notifying the ECT team and for the proposal to be accepted.

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
