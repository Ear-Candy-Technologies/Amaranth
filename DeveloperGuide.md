# Developing Guide

# Español

## Introducción

Este ReadMe contiene todas las normas y guias necesarias para el desarrollo y aportación dentro de Amaranth. Todos los puntos a continuación estan basados en buenas prácticas de C++ y los [estándares de código de JUCE](https://juce.com/discover/stories/coding-standards) (recomendamos tomar estás prácticas de escritura como base principal para el desarrollo en Amaranth). Si tienes alguna pregunta que no este aclarada en este ReadMe puedes resolverla en la comunidad de Ear Candy Technologies en [Discord](https://discord.gg/WJvn7m2KwJ) en el canal de Amaranth.

## Contribuciones

### Revisiones de código

Al momento de hacer un Pull Request siempre se hará una revisión de tu codigo por parte del equipo de Ear Candy Technologies con el fin de garantizar que no haya ningún problema con el proyecto principal ni tenga código mal implementado. Si es necesario hacer algún cambio se notificará a la persona en el Pull Request con los comentarios correspondientes, por lo que tomar en cuenta todas estas normas pueden eficientar los tiempos de respuesta.

### Uso de GitHub

1. Se va a tener un [Scrum Board](https://plum-citrus-d4f.notion.site/da4ed25887734268b30b65c37f3fa09f?v=7616b4897aba46cc94e2e9934c20e5fd) donde estarán todos los issues actuales del proyecto, debes elegir algún issue de la columna de backlog, colocar tu usuario de discord, el nombre del branch que vas a crear y pasarlo a la columna de "En proceso".
2. Estos issues tambien van a estar presentes en el repositorio de GitHub.
3. Posteriormente se debe de abrir una branch que salga de develop con el nombre presentado en el scrum board.
4. Al terminar tu implementación realiza el Pull Request y avisar en Discord que acabas de terminar el feature y esta listo para revisión, si todo esta bien se aceptará y se hará merge. Acto seguido se borrará el branch.
5. Si llevas mucho tiempo en un solo issue es recomendable hacer `git rebase` para que no sucedan conflicto al momento del PR.
6. Los issues propuestos tanto en el scrum board como en GitHub son propuestas del equipo de Ear Candy Technologies, sin embargo, estamos totalmente abiertos a nuevos features y propuestas de desarrollo. Para esto, es necesario mandar mensaje para notificar al equipo de ECT y que se acepte la propuesta.

### ¿Cómo empezar mi desarrollo?

1. Si se va a añadir una clase nueva debe estar dividio en archivos .h y .cpp
2. Los archivos nuevos siempre deben de ir en las carpetas correspondientes de DSP, GUI, Utilities, etc. según sea su funcionalidad.
3. Cualquier parámetro que se tenga que añadir al AudioProcessorValueTreeState, tanto el nombre como el ID, se deben de declarar en el archivo ParamsHelper.h y seguir la estructura de los parametros previamente creados.
4. Al momento de crear una nueva clase se debe de comentar brevemente en el archivo .h explicando para que es cada método, función y/o variable declarada (tomar de referencia la clase de Oscilador para esto).
5. Cualquier duda de desarrollo y/o de estructura del proyecto favor de preguntar en Discord.

### Mensajes de commits

Los commits deben estar compuestos de

```
<resumen breve del commit de una linea>
<descripción que exploque la implementación en detalle>
```
