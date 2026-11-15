# Proyecto de Verificación Formal: Algoritmo de División mediante Restas Sucesivas

## 1. Descripción del proyecto

Este proyecto implementa un algoritmo de división entera mediante restas
sucesivas, desarrollado en lenguaje C. Su objetivo es calcular el
cociente y el residuo de una división sin utilizar directamente el
operador de división.

El algoritmo funciona restando repetidamente el divisor al dividendo
mientras el residuo sea mayor o igual que el divisor. Por cada resta
realizada, el cociente aumenta en una unidad.

El programa trabaja con las siguientes condiciones:

-   El dividendo debe estar entre 0 y 1.000.000.
-   El divisor debe estar entre 1 y 1.000.000.
-   El cociente y el residuo deben cumplir las propiedades matemáticas
    de la división entera.

La propiedad principal que debe cumplir el algoritmo es:

`dividendo = divisor * cociente + residuo`

Además, el residuo debe ser mayor o igual que cero y menor que el
divisor.

El proyecto incorpora especificaciones formales mediante ACSL y utiliza
Frama-C para realizar la verificación formal del algoritmo.

## 2. Tecnologías y herramientas utilizadas

Las herramientas utilizadas durante el desarrollo del proyecto son:

  -----------------------------------------------------------------------
  Herramienta                         Utilización
  ----------------------------------- -----------------------------------
  Lenguaje C                          Desarrollo del algoritmo de
                                      división.

  Visual Studio Code                  Edición y organización del código
                                      fuente.

  WSL                                 Entorno Linux utilizado desde
                                      Windows.

  GCC                                 Compilación y ejecución del
                                      programa.

  Frama-C                             Análisis y verificación formal del
                                      código.

  WP                                  Complemento de Frama-C utilizado
                                      para la verificación deductiva.

  Alt-Ergo 2.6.4                      Demostrador automático de
                                      obligaciones de prueba.

  ACSL                                Lenguaje utilizado para escribir
                                      las especificaciones formales.
  -----------------------------------------------------------------------

**Sistema operativo:** Windows utilizando el Subsistema de Windows para
Linux (WSL). La distribución y su versión específica no fueron
registradas.

**Versiones:** La versión confirmada de Alt-Ergo es 2.6.4. Las versiones
de GCC y Frama-C no fueron registradas durante las pruebas.

## 3. Estructura del proyecto

El repositorio contiene el siguiente archivo:

``` text
Verificacion-Division/
│
├── division_resta.c
│
└── README.md
```

-   **division_resta.c:** contiene el código fuente del algoritmo de
    división, las especificaciones formales ACSL, la función principal y
    los casos de prueba.
-   **README.md:** contiene la documentación del proyecto y las
    instrucciones para compilar, ejecutar y verificar el programa.

## 4. Requisitos previos

Para ejecutar y verificar el proyecto se necesita:

-   Un equipo con Windows.
-   Subsistema de Windows para Linux (WSL).
-   Una distribución Linux instalada mediante WSL.
-   Compilador GCC.
-   Frama-C.
-   Complemento WP de Frama-C.
-   Demostrador automático Alt-Ergo.
-   El archivo fuente `division_resta.c`.

Se recomienda utilizar Visual Studio Code para consultar y editar el
código, aunque no es indispensable para ejecutar los comandos desde WSL.

Las herramientas GCC, Frama-C y Alt-Ergo deben estar instaladas y
disponibles desde la terminal de Linux.

## 5. Instalación y configuración

### 5.1. Acceder a WSL

Abrir una terminal de Windows, como PowerShell, y ejecutar:

``` bash
wsl
```

Este comando permite ingresar al entorno Linux de WSL.

### 5.2. Acceder a la carpeta del proyecto

Una vez dentro de WSL, ingresar a la carpeta donde se encuentra el
archivo `division_resta.c` utilizando:

``` bash
cd "Nombre de la carpeta"
```

Se debe reemplazar `Nombre de la carpeta` por la ruta correspondiente al
proyecto.

En el entorno utilizado durante el desarrollo, la carpeta estaba ubicada
en:

``` bash
cd "/mnt/c/VS UNIVERSIDAD/.vscode/Proyecto Teoría"
```

Si el proyecto se descarga desde GitHub, se debe utilizar la ruta donde
se haya guardado y extraído el repositorio.

### 5.3. Comprobar las herramientas

Para comprobar que GCC está disponible:

``` bash
gcc --version
```

Para comprobar Frama-C:

``` bash
frama-c -version
```

Para comprobar Alt-Ergo:

``` bash
alt-ergo --version
```

## 6. Ejecución del programa

La compilación y ejecución normal del programa se realiza mediante GCC
desde la terminal de WSL.

Una vez ubicada la terminal en la carpeta del proyecto, ejecutar:

``` bash
gcc -Wall -o division division_resta.c && ./division
```

Explicación del comando:

-   `gcc`: inicia el compilador de C.
-   `-Wall`: habilita las advertencias del compilador.
-   `-o division`: establece el nombre del archivo ejecutable.
-   `division_resta.c`: indica el archivo fuente que se va a compilar.
-   `&&`: ejecuta el siguiente comando únicamente si la compilación
    termina correctamente.
-   `./division`: ejecuta el programa compilado.

Si la compilación es correcta, el programa se ejecutará automáticamente
y mostrará los resultados de los casos de prueba definidos en la función
`main()`.

## 7. Ingreso de datos

El programa no solicita datos manualmente mediante el teclado.

Los valores que se utilizan están definidos directamente en la función
`main()`, mediante llamadas a la función `probar()`.

El programa ejecuta automáticamente once casos de prueba que permiten
comprobar diferentes situaciones:

-   Divisiones exactas.
-   Divisiones con residuo.
-   Dividendo igual a cero.
-   Divisor mayor que el dividendo.
-   Valores máximos permitidos.
-   Divisor igual a cero.
-   Valores negativos.
-   Valores que superan el límite establecido.

La función `probar()` verifica que las entradas estén dentro de los
límites permitidos antes de llamar a la función `dividir()`.

Cuando los valores son válidos, se presenta el cociente y el residuo.
Cuando no cumplen las condiciones establecidas, se muestra un mensaje
indicando que la entrada es inválida.

## 8. Verificación formal en Frama-C

La verificación formal permite analizar matemáticamente las propiedades
especificadas en el código mediante ACSL.

Para realizar este procedimiento se utiliza Frama-C con el complemento
WP (Weakest Precondition) y el demostrador automático Alt-Ergo.

La función que se verifica es `dividir`.

### 8.1. Verificación con WP y RTE

Ejecutar el siguiente comando desde la carpeta del proyecto:

``` bash
frama-c -wp -wp-rte -wp-prover alt-ergo -wp-fct dividir division_resta.c
```

Explicación de las opciones:

-   `frama-c`: inicia la herramienta Frama-C.
-   `-wp`: activa el complemento WP para generar y demostrar
    obligaciones de prueba.
-   `-wp-rte`: solicita comprobaciones relacionadas con posibles errores
    en tiempo de ejecución.
-   `-wp-prover alt-ergo`: utiliza Alt-Ergo como demostrador automático.
-   `-wp-fct dividir`: limita el análisis a la función `dividir`.
-   `division_resta.c`: indica el archivo que será analizado.

**Resultado obtenido durante las pruebas:**

``` text
[wp] 20 goals scheduled
[wp] [Timeout] typed_dividir_assert_rte_signed_overflow_3
[wp] Proved goals: 21 / 22

Terminating: 1
Unreachable: 1
Qed: 14
Alt-Ergo 2.6.4: 5
Timeout: 1
```

En esta ejecución se observa que 21 de los 22 objetivos fueron
demostrados. Un objetivo terminó en `Timeout`, por lo que no se puede
considerar completamente demostrado.

También aparecieron advertencias relacionadas con comprobaciones RTE
omitidas por limitaciones de compatibilidad:

-   Punteros no alineados.
-   Llamadas mediante punteros a funciones no válidos.

### 8.2. Verificación con WP sin RTE

También se realizó una segunda ejecución utilizando el siguiente
comando:

``` bash
frama-c -wp -wp-prover alt-ergo -wp-fct dividir division_resta.c
```

En esta ejecución no se incluye la opción `-wp-rte`.

**Resultado obtenido durante las pruebas:**

``` text
[kernel] Parsing division_resta.c (with preprocessing)
[wp] Warning: Missing RTE guards
[wp] 15 goals scheduled
[wp] [Cache] found:3
[wp] Proved goals: 17 / 17

Terminating: 1
Unreachable: 1
Qed: 12
Alt-Ergo 2.6.4: 3
```

En esta segunda ejecución, Frama-C informó que los 17 objetivos
presentados como demostrados fueron probados.

Sin embargo, apareció la advertencia `Missing RTE guards`, que indica
que no se generaron todas las comprobaciones de protección relacionadas
con errores en tiempo de ejecución.

Por este motivo, este resultado no debe confundirse con una verificación
completa de todas las comprobaciones RTE.

### 8.3. Interpretación de los resultados

Los resultados de Frama-C pueden presentar diferentes estados:

-   **Proved:** la obligación de prueba fue demostrada.
-   **Timeout:** el demostrador no consiguió resolver la obligación
    dentro del tiempo disponible.
-   **Unreachable:** corresponde a una condición o ruta identificada
    como inalcanzable.
-   **Qed:** indica obligaciones resueltas mediante el motor de
    demostración interno de Frama-C.
-   **Alt-Ergo:** indica obligaciones demostradas utilizando el
    demostrador automático.
-   **Warning:** informa sobre advertencias que deben revisarse para
    comprender las limitaciones del análisis.

Es importante diferenciar entre los objetivos demostrados y aquellos que
no pudieron demostrarse.

Los resultados documentados corresponden a las ejecuciones realizadas
durante el desarrollo del proyecto.

## 9. Especificaciones formales ACSL

Las especificaciones ACSL se encuentran directamente dentro del archivo
`division_resta.c`.

Se identifican mediante comentarios especiales que comienzan con `/*@` y
permiten expresar propiedades matemáticas y condiciones sobre el
comportamiento del programa.

En el proyecto se utilizan las siguientes especificaciones:

### 9.1. Precondiciones (`requires`)

Establecen las condiciones que deben cumplirse antes de ejecutar la
función:

-   El dividendo debe estar entre 0 y 1.000.000.
-   El divisor debe estar entre 1 y 1.000.000.
-   Los punteros de salida deben ser válidos.
-   Los punteros de salida deben estar separados.

### 9.2. Asignaciones (`assigns`)

Indican qué posiciones de memoria pueden modificarse durante la
ejecución de la función.

En este caso, se permite modificar el contenido de las variables
apuntadas por `cociente` y `residuo`.

### 9.3. Poscondiciones (`ensures`)

Establecen las propiedades que deben cumplirse al finalizar la función:

-   La igualdad fundamental de la división.
-   El cociente debe ser mayor o igual que cero.
-   El residuo debe ser mayor o igual que cero y menor que el divisor.

### 9.4. Invariantes del ciclo (`loop invariant`)

Permiten expresar propiedades que deben mantenerse durante las
iteraciones del ciclo `while`.

En este algoritmo se utilizan para conservar la relación entre el
dividendo, el divisor, el cociente y el residuo.

### 9.5. Asignaciones del ciclo (`loop assigns`)

Indican las variables que pueden modificarse dentro del ciclo.

En este caso son `q` y `r`.

### 9.6. Variante del ciclo (`loop variant`)

Se utiliza para expresar una medida que disminuye durante las
iteraciones y permite justificar la terminación del ciclo.

En este proyecto se utiliza el residuo `r` como variante.

## 10. Resultados esperados

Al ejecutar el programa con GCC se deben observar los resultados
correspondientes a los once casos definidos en `main()`.

Los resultados obtenidos durante la ejecución fueron:

``` text
20 / 5 -> cociente = 4, residuo = 0
17 / 5 -> cociente = 3, residuo = 2
0 / 5 -> cociente = 0, residuo = 0
3 / 8 -> cociente = 0, residuo = 3
1000000 / 1 -> cociente = 1000000, residuo = 0
1000000 / 1000000 -> cociente = 1, residuo = 0
999999 / 1000000 -> cociente = 0, residuo = 999999
10 / 0 -> entrada invalida (se requiere 0<=a<=1000000 y 1<=b<=1000000)
-10 / 3 -> entrada invalida (se requiere 0<=a<=1000000 y 1<=b<=1000000)
10 / -3 -> entrada invalida (se requiere 0<=a<=1000000 y 1<=b<=1000000)
1000001 / 7 -> entrada invalida (se requiere 0<=a<=1000000 y 1<=b<=1000000)
```

Estos resultados permiten observar el comportamiento del algoritmo ante
entradas válidas e inválidas.

Por otra parte, al realizar la verificación formal se deben observar los
resultados y advertencias generados por Frama-C, teniendo en cuenta las
diferencias entre las dos ejecuciones documentadas.

## 11. Diferencia entre ejecución y verificación formal

El proyecto utiliza dos procedimientos diferentes que cumplen propósitos
complementarios.

**Ejecución mediante GCC:**

Permite compilar y ejecutar el programa con los casos de prueba
definidos. De esta manera se comprueba el comportamiento del algoritmo y
los resultados que produce.

**Verificación formal mediante Frama-C:**

Permite analizar las especificaciones ACSL y generar obligaciones de
prueba para comprobar formalmente las propiedades del algoritmo.

Por lo tanto, la ejecución normal permite observar el funcionamiento del
programa con determinados valores, mientras que la verificación formal
analiza las propiedades especificadas mediante métodos deductivos.

Ambos procedimientos son importantes y no deben confundirse.

## 12. Autores

Proyecto desarrollado por:

-   Isabela Zapata
-   Daniel Rodríguez
-   Thomas Otálvaro

**Programa:** Ingeniería de Sistemas\
**Asignatura:** Teoría de la Computación\
**Clase:** 4357\
**Semestre:** Segundo semestre
