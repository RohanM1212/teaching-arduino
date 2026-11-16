# Leçon 8 : Projet intégrateur 2 – Montez votre propre circuit

Durée estimée : ~90 minutes
Groupe d’âge : 11 à 14 ans
Préalables : Leçons 1 à 7. Les élèves doivent être à l’aise avec les DEL, les boutons, les potentiomètres, les servomoteurs, les instructions switch et les boucles.

## Aperçu

Même principe que le projet intégrateur 1, mais plus difficile. Les élèves ont maintenant plus d’outils, et la barre est plus haute. Aucune consigne, aucun circuit à copier. Ils montent ce qu’ils veulent avec tout ce qu’ils ont appris aux leçons 1 à 7.

## Objectifs d’apprentissage

Les élèves apprendront :
- Comment concevoir un circuit plus complexe avec tout ce qu’ils savent jusqu’à maintenant
- Comment écrire du code qui utilise au moins une boucle ou une instruction switch
- Comment expliquer chacune de leurs décisions
- Comment dépanner leur propre circuit quand quelque chose ne fonctionne pas

## Matériel

Si vous travaillez avec des pièces physiques, chaque élève aura besoin de :
- 1 carte Arduino Uno R3
- 1 plaque d’essai
- Plusieurs DEL (de couleurs différentes si possible)
- Plusieurs résistances de 220 Ω
- 1 bouton-poussoir
- 1 résistance de 10 kΩ (résistance de rappel)
- 1 potentiomètre
- 1 servomoteur
- 1 condensateur de 100 microfarads (polarisé)
- Plusieurs fils de connexion (jumpers)
- 1 câble USB
- Un ordinateur avec le logiciel Arduino IDE installé

Si vous travaillez avec Tinkercad, chaque élève aura besoin de :
- Un ordinateur
- Une connexion Internet
- Un compte Tinkercad
- Aucun condensateur n’est nécessaire dans Tinkercad

### Les exigences (à présenter au début)

- Utiliser au moins 3 composants
- Le code doit contenir au moins une instruction switch ou une boucle
- Les élèves doivent pouvoir expliquer à quoi sert chaque partie et pourquoi elle est là
- Ils ne peuvent pas monter la même chose qu’au projet intégrateur 1

### Moment d’apprentissage

Pendant le montage, quand un élève bloque, posez-lui des questions au lieu de régler le problème à sa place. « Qu’est-ce que tu veux que cette partie fasse? » fonctionne mieux que de simplement lui montrer.

## Avant la leçon

Pour le montage physique :
- Trier tous les composants pour que les élèves n’aient pas à chercher les pièces.
- Garder les exemples fonctionnels des leçons 1 à 7 au cas où les élèves auraient besoin d’une référence.
- NE PAS préparer de circuit déjà monté. Il n’y a pas d’exemple à montrer cette fois-ci.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

Pour Tinkercad :
- Avoir les leçons 1 à 7 enregistrées dans Tinkercad comme référence.
- (Facultatif) Remplir le sondage avant la leçon (https://forms.gle/HJoWXzzGJgc2NwMN8).

## Déroulement de la leçon

### Ouverture (5 minutes)

Annoncez à la classe ce qui se passe aujourd’hui. Même principe qu’au projet intégrateur 1, mais ils ont beaucoup plus d’outils maintenant.

Demandez : « Qu’est-ce que vous vouliez monter au projet intégrateur 1, mais pour lequel vous n’aviez pas encore les composants ou les connaissances? »

Laissez quelques élèves répondre. Ça lance les idées avant le remue-méninges.

### Orientation et exigences (15 minutes)

Passez en revue ce qu’ils ont maintenant à leur disposition :

Composants qu’ils connaissent :
- DEL
- Bouton-poussoir
- Potentiomètre
- Servomoteur
- Résistances et condensateur

Code qu’ils connaissent :
- digitalWrite et digitalRead
- analogRead et analogWrite
- delay et millis()
- Instructions if et else
- Instructions switch
- Boucles for et while
- Variables
- map()

Présentez les quatre exigences de la section ci-dessus.

Proposez une idée d’exemple sans la monter. Par exemple : « Vous pourriez faire un servomoteur qui va à un angle différent selon le mode dans lequel il se trouve, avec un bouton qui fait passer d’un mode à l’autre dans une instruction switch. » Précisez tout de suite que ce n’est qu’une idée et qu’ils doivent trouver la leur.

Une règle : ils ne peuvent pas simplement copier le code d’une leçon précédente. Ce doit être quelque chose de nouveau, même si ça utilise les mêmes concepts.

### Remue-méninges (10 minutes)

Avant de toucher à un seul composant, chaque élève écrit 3 idées. Elles n’ont pas besoin d’être bonnes. Seulement 3 choses différentes.

Circulez pendant qu’ils écrivent. Si un élève bloque, demandez-lui :
- « Qu’est-ce que tu aurais voulu ajouter au projet intégrateur 1, mais que tu n’as pas pu? »
- « Quelle est la chose la plus intéressante que tu as montée aux leçons 6 ou 7? »
- « Qu’est-ce que tu monterais si tu avais encore plus de composants? »

Après 10 minutes, chaque élève choisit une idée et l’encercle. C’est ce qu’il va monter.

Si deux élèves choisissent la même idée, ce n’est pas grave. Leur code et leur montage finiront par être différents de toute façon.

### Montage (60 minutes)

Les élèves montent leur circuit. Circulez et aidez-les.

Quand un élève bloque, posez-lui des questions au lieu de régler le problème à sa place :
- « Qu’est-ce que tu veux que cette partie fasse? »
- « Qu’est-ce que cette ligne de code dit à l’Arduino? »
- « Qu’est-ce que tu as déjà essayé? »

Intervenez directement seulement si l’élève bloque sur le même problème depuis plus de 5 minutes et que les questions ne l’aident pas.

Élèves qui terminent en avance : demandez-leur d’ajouter une fonctionnalité. Ils utilisent seulement des DEL et un bouton? Peuvent-ils ajouter le servomoteur? Ils ont une instruction switch avec deux cas? Peuvent-ils en ajouter un troisième?

Élèves en difficulté : simplifiez avec eux. Demandez-leur à quoi ressemble la version minimale de leur idée. Montez celle-là d’abord, puis ajoutez-y des éléments ensuite.

Élèves qui ont copié une leçon précédente ou le projet intégrateur 1 : demandez-leur de changer au moins trois choses pour que le projet devienne le leur.

Quand il reste 10 minutes, dites à la classe d’arrêter d’ajouter des fonctionnalités et de faire fonctionner ce qu’ils ont. Des fils mal branchés et des fonctionnalités à moitié terminées n’aident pas au moment de la démonstration.

### Démonstrations (10 minutes)

Faites le tour de la classe. Chaque élève a 60 secondes pour :
- Montrer son circuit en fonctionnement
- Expliquer une décision qu’il a prise
- Nommer une chose qu’il ajouterait s’il avait plus de temps

N’évaluez pas la complexité. Évaluez si l’élève peut expliquer ce qu’il a monté et pourquoi.

### Clôture (5 minutes)

Demandez à la classe :
- Qu’est-ce qui était plus difficile dans ce projet intégrateur, comparé au premier?
- Quelqu’un a-t-il utilisé un composant qu’il n’avait pas touché depuis la leçon où on l’a présenté?
- Qu’est-ce que vous monteriez si vous pouviez avoir n’importe quel composant?

Rangement :
- Débrancher le câble USB
- Démonter avec soin et remettre les composants dans les bacs
- Faire attention aux fils du servomoteur et aux pattes du condensateur

## Évaluation

Pendant la leçon :
- L’élève a-t-il conçu son propre circuit ou copié une leçon précédente?
- Le circuit respecte-t-il les quatre exigences?
- L’élève peut-il expliquer son code ligne par ligne?

Billet de sortie :
1. Dessine ton circuit de mémoire.
2. Une chose que tu as trouvée par toi-même aujourd’hui.
3. (Facultatif) Remplis le sondage après la leçon (https://forms.gle/KjvaqDAQ5QRLcHXCA).

Réussite : chaque élève a un circuit fonctionnel qu’il a conçu lui-même et qu’il peut expliquer.

## Problèmes fréquents

### L’élève ne trouve pas d’idée
- Commencer plus petit : lui demander de reprendre quelque chose du projet intégrateur 1 et d’y ajouter un servomoteur ou une boucle
- S’il bloque complètement, lui donner l’idée du servomoteur à plusieurs modes comme point de départ

### L’élève copie le projet intégrateur 1 ou une leçon précédente
- Lui demander de changer le comportement d’au moins trois façons
- « Qu’est-ce qui ferait que ce projet est le tien plutôt que quelque chose qu’on a déjà monté? »

### Le circuit fonctionne, mais l’élève ne peut pas l’expliquer
- Passer le code en revue ligne par ligne avec lui
- Lui demander de lire chaque ligne à voix haute et de dire ce qu’elle fait selon lui

### L’élève termine en 20 minutes
- Lui demander ce qu’il ajouterait s’il avait un composant de plus
- Peut-il ajouter un troisième mode à son instruction switch?

## Autres situations

Besoin de soutien :
- Les laisser travailler avec un partenaire
- Leur donner un circuit de départ avec deux composants déjà branchés et les laisser le compléter

Avancé :
- Pouvez-vous faire en sorte que votre circuit fasse quatre choses différentes avec une instruction switch?
- Pouvez-vous utiliser millis() au lieu de delay() pour que le bouton reste réactif tout le temps?

## Notes pour l’enseignant

Tenez bon sur le remue-méninges. Comme au projet intégrateur 1, les élèves qui le sautent bloquent plus vite. 3 idées avant que quiconque touche à un composant.

La règle « ne pas refaire le projet intégrateur 1 » demande du jugement de votre part. Une veilleuse au projet intégrateur 1 et une lampe d’ambiance au projet intégrateur 2 pourraient être trop semblables. Fiez-vous à ce que vous connaissez de l’élève. L’esprit de la règle, c’est qu’il doit réellement utiliser quelque chose de nouveau des leçons 5 à 7.

La démonstration compte. Même si un circuit fonctionne à peine, présenter son travail donne à chaque élève l’impression d’avoir construit quelque chose de concret. Gardez-la courte, mais ne la sautez pas.

Votre rôle dans cette leçon est le même qu’au projet intégrateur 1. Vous n’enseignez pas de nouvelle matière. Vous posez de bonnes questions et vous laissez les élèves travailler.

Durée :
- Ouverture : 5 min
- Orientation et exigences : 15 min
- Remue-méninges : 10 min
- Montage : 60 min
- Démonstrations : 10 min
- Clôture : 5 min
- Aucune marge. Si une partie déborde, prenez le temps sur le montage, et non sur les démonstrations.

Préparation :
- Trier tous les composants avant la séance
- Avoir les leçons 1 à 7 enregistrées et prêtes à consulter

*Fin de la leçon 8*
