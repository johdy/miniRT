# Overview

L’objectif de votre programme est de modéliser des images en respectant le protocole de raytracing.

Ces images doivent représenter une scène, vue d’un angle défini et contenant des objet géometriques simples, chacun avec son système d’éclairage.

# Mandatory part

• Votre projet doit utiliser la minilibX. Soit la version disponible sur votre OS, ou depuis les sources. Si vous travaillez depuis les sources, vous devez appliquer les mêmes règles que pour la libft. 

• Votre programme doit être capable de changer la taille de la propriété unique d’un objet : diamètre pour une sphère, et la hauteur et longueur pour un cylindre.

• Votre programme doit pouvoir appliquer des transformations aux objets, lumières et caméra : translation et rotation (excepté pour les sphères et lumières qui ne peuvent pas être tournées).

• Gestion de la lumière : luminosité, ombres, lumière d’ambiance (les objets ne sont jamais complètement dans le noir). Vous devez mettre en œuvre un éclairage ambiant et diffus.

• Votre programme doit prendre en premier argument une description de scène avec un fichier .rt.

# Usage

./miniRT scenes/pickascene.rt