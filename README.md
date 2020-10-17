# Threadable

Clase que permite heredar metodos de trazabilidad y gestion de procesos a lo largo del tiempo.

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/Threadable.git .
```

Esto creara el directorio Threadable de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la última vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la última versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la última versión siguiendo los pasos de Selección de versión

## Uso

Es posible realizar una instancia de la clase Threadable, pero no generaria ningun. Su uso consiste en que sea heredada por una clase que reimplemente al menos el metodo Tick().

Al reimplementar el metodo Tick(), se consigue que tras agotar los contadores de intervalos al llamar continuamente a Loop(), se invoque Tick() y con esto se logra ejecutar cualquier logica implementada en la clase derivada.


## Links

- [Cambios de version](CHANGELOG.md)
- [Repositorio](https://gitlab.com/arduinolibraries/Threadable/-/tree/master)