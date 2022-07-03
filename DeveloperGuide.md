# Developer Guide

# Español

## Introducción

Este readme contiene todas las normas y guias necesarias para el desarrollo y aportación dentro de Amaranth. Todos los puntos a continuación estan basados en buenas prácticas de C++ y los [estándares de código de JUCE](https://juce.com/discover/stories/coding-standards). Si tienes alguna pregunta que no este aclarada en este readme puedes resolverla en la comunidad de Ear Candy Technologies en [Discord](https://discord.gg/WJvn7m2KwJ) en el canal de Amaranth.

## Contribuciones

### Revisiones de código

Al momento de hacer un pull request siempre se hará una revisión de tu codigo por parte del equipo asignado por Ear Candy Technologies con el fin de garantizar que no haya ningún problema con el proyecto principal ni tenga código mal implementado. Si es necesario hacer algún cambio se notificará a la personas con los comentarios correspondientes por lo que tomar en cuenta todas estas normas pueden eficientar los tiempos de respuesta.

### Uso de GitHub

1. Se va a tener un Scrum Board donde estaran todos los issues actuales del proyecto, debes elegir uno color tu nombre y usuario de github y pasarlo a la columna de "En proceso". 
2. Posteriormente se debe de abrir una branch que salga de develop con el nombre presentado en el scrum board.
3. Al terminar tu implementación realiza el Pull request y avisa en Discord que acabas de terminar el feature y esta listo para revisión, si todo esta bien se aceptará y se hará merge además de borrarse la branch.
4. Si llevas mucho tiempo en un solo issue es recomendable hacer `git rebase` para que no sucedan conflicto al momento del PR.

### ¿Cómo empezar mi desarrollo?

1. Si se va a añadir una clase nueva esta debe estar dividio en .h y .cpp
2. Los archivos nuevos siempre deben ir en las carpetas correspondientes ya sea de DSP, GUI, Utilities, etc.
3. Al hacer el include de alguna clase de DSP se debe de declarar en el archivo Global_DSP_Includes tanto .h como .cpp con el fin de que todas las clases tengan el namespace `Amaranth`. Ejemplo de una declaración de clase: `Amaranth::SynthVoice synth`.
4. Cualquier parametro que se tenga que añadir al AudioProcessorValueTreeState tanto el nombre como ID se deben de declarar en el archivo ParamsHelper.h y seguir la estructura de los parametros previamente creados.

## Estilo de código

### Nombres

* Use `static constexpr float constVariable = 1;` instead of Defines
* `class ThisIsANameClass`
* `void esteEsUnNombreDeFuncion()`

### Mensajes de commits

Los commits deben estar compuestos de

```
<resumen breve del commit de una linea>
<descripción que exploque la implementación en detalle>
```
