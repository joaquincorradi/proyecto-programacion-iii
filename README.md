# Proyecto final - Programación III

[![Seguir](https://img.shields.io/badge/joaquincorradi-%238B5CF6.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/joaquincorradi/) [![Seguir](https://img.shields.io/badge/sanrearte-%238B5CF6.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/sanrearte/) [![Seguir](https://img.shields.io/badge/IgnaAltamirano00-%238B5CF6.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/IgnaAltamirano00/)

## _Introducción_

Una empresa argentina realiza diariamente el inventario físico de una gran diversidad de productos con diferentes códigos de _QR_ y en diferentes depósitos. El software de escaneo que se usa en el inventariado físico, lamentablemente, es muy elemental y arroja una tabla de _Excel_ de infinidad de filas que resultan humanamente ilegibles y difíciles de procesar para obtener información útil a la empresa:

- Área de Compras: no detecta a tiempo cuáles artículos alcanzan el mínimo por el cual tomar la decisión de reponerlos.
- Área de ventas: se encuentra con la dificultad de no poder atender rápidamente a los clientes al no saber la existencia o no de determinado artículo, al momento de consulta de la información.
- Área de Marketing: hace lecturas extensas para detectar aquellos artículos de mayor cantidad para el lanzamiento de promociones de liquidación de stock.

La empresa pone a disposición la tabla de _Excel_ a un grupo de programadores con la finalidad de que le ayuden a procesar la información de la misma.

## _Enunciado_

Realizar una aplicación informática que lea un archivo `.csv` que brinda la empresa y que por terminal permita la visualización de la siguiente información:

- Cantidad total de artículos diferentes.
- Cantidad total de artículos.
- Listado de artículos que están en el mínimo de stock.
- Listado de artículos que están en el mínimo de stock y por depósito.
- Stock individual de cada artículo.
- Stock individual de cada artículo según depósito.
- Los artículos que igualan o superen determinada cantidad en stock.

## _Consideraciones del archivo `.csv`_

- La cantidad de depósitos puede variar.
- La cantidad de artículos diferentes puede variar.

## _Uso_

    main [Argumentos] database.csv

#### Argumentos posibles:

| Argumento                            | Descripción                                                               |
| ------------------------------------ | ------------------------------------------------------------------------- |
| `total_art_dif`                      | Cantidad total de artículos diferentes listo                              |
| `total_art`                          | Cantidad total de artículos listo                                         |
| `min_stock [n]`                      | Listado de artículos con cantidad _n_ o menos de stock                    |
| `min_stock [n],[deposito]`           | Listado de artículos con cantidad _n_ o menos de stock según un depósito  |
| `stock [nombre_articulo]`            | El stock total del artículo ingresado como argumento listo                |
| `stock [nombre_articulo],[depósito]` | El stock del artículo en un depósito listo                                |
| `max_Stock [n]`                      | Listado de aquellos artículos cuyo stock es igual o supera el número _n_. |
