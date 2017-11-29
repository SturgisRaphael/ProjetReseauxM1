1. 3) Le client sur la VM1 se connecte sans problème à la VM3. Par contre, il n'arrive pas à se connecter à la VM3-6 (La VM1 semble ne pas trouver un chemin vers la VM3-6). Est ce que c'est le comportement attendu? Peut-être qu'il faut re-vérifier les configs.sls et Vagranfile des VM1, VM1-6, VM3, VM3-6.

Pour utiliser les VMs, il faut d'abord faire un vagrant destroy de toutes les machines (Wissam ne m'a pas laissé le temps :P). Ensuite vagrant up. Pour configurer une machine avec salt :
Dans un terminal : sudo -s 
En cours, le mdp c'est m1reseaux.
Après, salt-call state.apply

Je me souviens plus comment accéder aux fichiers de partage. Mais on peut quand même placer des fichiers (depuis votre ordi) dans .vagrant dans le dossier de la VM. Pour récupérer ces fichiers depuis la VM, on peut faire cd ../../vagrant. J'y ai mis les fichiers de pour les clients en IPv4 et IPv6.
