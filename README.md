#  Robot Basket - Multi-fonction (Arduino)

Ce projet présente un robot autonome capable de suivre une ligne, d'éviter des obstacles et de lancer des balles dans un panier de basket. Le développement a été réalisé de manière itérative à travers 5 étapes clés (checkpoints).



## Fonctionnalités
- **Suivi de Ligne** : Utilisation de capteurs infrarouges pour rester sur la trajectoire.
- **Détection d'Obstacles** : Capteur ultrasonique pour stopper ou contourner les objets.
- **Lanceur de Balles** : Mécanisme motorisé pour l'éjection des balles.
- **Navigation Intelligente** : Logique de décision basée sur l'environnement (aire de jeu).

## 📊 Étapes du Projet (Checkpoints)
Le projet est structuré en 5 phases de développement :
1. **Checkpoint 1** : Mouvement de base et calibration des moteurs.
2. **Checkpoint 2** : Implémentation du suivi de ligne (Line Follower).
3. **Checkpoint 3** : Intégration du capteur ultrason et gestion des obstacles.
4. **Checkpoint 4** : Activation et test du mécanisme de lancer.
5. **Checkpoint 5** : Code final optimisé combinant toutes les fonctions pour le match.

##  Aire de Jeu
Le robot évolue sur un terrain spécifique défini par les fichiers images inclus :
<img width="653" height="725" alt="Aire du jeu(1)" src="https://github.com/user-attachments/assets/f1282b9f-49e8-4dd1-ab41-98dae3826ed6" />
 Tracé des lignes et zones de tir.



##  Matériel Utilisé
- Microcontrôleur **Arduino** uno
- Châssis de robot motorisé  4 roues
- Capteurs de ligne infrarouges (IR)
- Capteur ultrasonique HC-SR04
- Servomoteur  (pour le lanceur)
- Pont en H L298N 

