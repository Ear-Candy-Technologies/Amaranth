# Developer Guide

# Español

## Introducción

Este ReadMe contiene todas las normas y guias necesarias para el desarrollo y aportación dentro de Amaranth. Todos los puntos a continuación estan basados en buenas prácticas de C++ y los [estándares de código de JUCE](https://juce.com/discover/stories/coding-standards) (recomendamos tomar estás prácticas de escritura como base principal para el desarrollo en Amaranth). 

Si tienes alguna pregunta que no esté aclarada en este ReadMe puedes resolverla en la comunidad de Ear Candy Technologies de [Discord](https://discord.gg/WJvn7m2KwJ) dentro del canal de #Amaranth.

## Contribuciones

### Revisiones de código

Al momento de hacer un Pull Request siempre se hará una revisión de tu código por parte del equipo de Ear Candy Technologies con el fin de garantizar que no haya ningún problema con el proyecto principal ni que tenga código mal implementado. Si es necesario hacer algún cambio se notificará a la persona a través del Pull Request con los comentarios correspondientes. Tomar en cuenta todas estas normas pueden eficientar los tiempos de respuesta.

### Uso de GitHub

1. Se va a tener un [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd) donde estarán todos los issues y bugs actuales del proyecto, debes elegir algún issue o bug de la columna de backlog, colocar tu usuario de github, el nombre del branch que vas a crear y pasarlo a la columna de "En proceso".
2. Estos issues tambien van a estar presentes en el repositorio de GitHub.
3. Posteriormente se debe de abrir una branch que salga de *develop* con el nombre presentado en el [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd). Si vas a trabajar en una branch ya existente deberás de abrir otra a partir de esa.
4. Al terminar tu implementación realiza el Pull Request y comparte el link del mismo en Discord para que sea revisado. Si todo está bien, se aceptará y se hará merge. Acto seguido se borrará el branch dónde trabajaste.
5. Si llevas mucho tiempo en un solo issue es recomendable hacer `git rebase` con *develop* para que no sucedan conflictos al momento del Pull Request.
6. Los issues propuestos tanto en el Scrum Board como en GitHub son propuestas por el equipo de Ear Candy Technologies, sin embargo, estamos totalmente abiertos a nuevos features y propuestas de desarrollo. Para esto, es necesario mandar mensaje notificando al equipo de ECT y que se acepte la propuesta.

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
