#include "libft/code/libft.h"
#include "../includes/tracker.h"

int main()
{
	{
		t_track	*track = ft_new_tracker();
		if (!track)
			return 1;
		char ***split = malloc(5 * sizeof(char**));
		split[0] = ft_split("je pense donc je suis", ' ');
		split[1] = ft_split("le coeur a ses raisons que la raison ignore", ' ');
		split[2] = ft_split("tout ce que je sais c que je ne sais rien", ' ');
		split[3] = ft_split("linux c cool", ' ');
		split[4] = NULL;
		printf("%p\n",ft_track_dim(&track, (void**)split, 3));
		ft_track_dim_free(&track, (void**)split, 3);
		ft_track_free_all(&track);
	}
	{
		t_track	*track = ft_new_tracker();
		if (!track)
			return 1;
		char ***split = malloc(5 * sizeof(char**));
		split[0] = ft_split("je pense donc je suis", ' ');
		split[1] = ft_split("le coeur a ses raisons que la raison ignore", ' ');
		split[2] = ft_split("tout ce que je sais c que je ne sais rien", ' ');
		split[3] = ft_split("linux c cool", ' ');
		split[4] = NULL;
		char **split2 = ft_split("etre ou ne pas etre", ' ');
		printf("%p\n",ft_track_dim(&track, (void**)split, 3));
		printf("%p\n",ft_track_dim(&track, (void**)split2, 2));
		ft_track_dim_free(&track, (void**)split, 3);
		ft_track_free_all(&track);
	}
	{
		t_track	*track = ft_new_tracker();
		if (!track)
			return 1;
		char ***split = malloc(5 * sizeof(char**));
		split[0] = ft_split("je pense donc je suis", ' ');
		split[1] = ft_split("le coeur a ses raisons que la raison ignore", ' ');
		split[2] = ft_split("tout ce que je sais c que je ne sais rien", ' ');
		split[3] = ft_split("linux c cool", ' ');
		split[4] = NULL;
		char **split2 = ft_split("etre ou ne pas etre", ' ');
		printf("%p\n",ft_track_dim(&track, (void**)split, 3));
		printf("%p\n",ft_track_dim(&track, (void**)split2, 2));
		ft_track_free(&track, (void**)split2[0]);
		ft_track_dim_free(&track, (void**)split, 3);
		ft_track_free_all(&track);
	}
	return 0;
}
