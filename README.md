# Tracker à la norme

## Un tracker, pourquoi?

Le tracker permet de référencer les pointeurs alloué dynamiqument dans un
annuaire. De cette façon adieu les **leaks** :wink:.

## Compilation

- Compilation de la librairie

```bash
make
```

- Compilation

```md
LIB_TRACKER	:=	-Ltracker -ltracker
$(CC) $(CFLAGS) $(LIB_TRACKER) ## and your main / objects  ... ##
```

## Usage

```c
#include "tracker/includes/tracker.h"

int	main(void)
{
	t_track	*track;

	track = ft_new_tracker();
	if (!track)
		return (1);

	// Do anything you want (just add all allocation [malloc...] to the tracker)


	ft_track_free_all(&track);
	return (0);
}
```

Le define `DEBUG_TRACK` dans le `tracker.h` permet de montrer d'éventuel erreurs
lors de l'utilisation du tracker.

***L'utilisation du tracker sur plusieurs dimensions ajoute les pointeurs
de toutes les dimensions***

***Donc dans le cas d'un split par exemple, s'il on veut free une ligne, il faudra la free avec le tracker avec `ft_track_free` ou `ft_track_dim_free` ou ne pas le free du tout et laisser `ft_track_free_all` de fin tout régler***
*(pas propre mais fonctionnel)*.


#### Avertissement

Par defaut, la fonction `ft_track_dim` retourne `NULL` si l'allocation du tracker échou
ou si le pointeur passé est `NULL`.
Dans le cas, d'une erreur d'allocation du tracker, **le pointeur est également free**.

Si l'on veut qu'en cas d'erreur d'allocation du tracker, le pointeur ne soit pas free.
Il faut changer le define `FREE_IF_ERROR` à 0.


## Prototypes

### Track
```c
// create a tracker
t_track	*ft_new_tracker(void);
// Add a pointer at n dimension to the tracker
void	*ft_track_dim(t_track **track, void **ptr, size_t level);
// Add a simple pointer to the tracker
void	*ft_track(t_track **track, void *ptr);
```
### Free
```c
// Remove the pointer and them dimensions from the tracker and free the pointer
// and all the dimensions
void	ft_track_dim_free(t_track **track, void **ptr, size_t level);
// Remove the pointer from the tracker and free the pointer
void	ft_track_free(t_track **track, void *ptr);
// Free all the pointers track by the tracker and free the tracker
void	ft_track_free_all(t_track **track);
```
