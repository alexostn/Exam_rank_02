#include "flood_fill.h"

//   typedef struct  s_point
//   {
//     int           x;
//     int           y;
//   }               t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.x >= size.x || cur.y >= size.y || cur.x < 0 || cur.y < 0 || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);//When we pass tab[begin.y][begin.x], it is not the coordinates, but access to the array element at the coordinates begin.y and begin.x
}
