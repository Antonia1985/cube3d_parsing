#include"../inc/cub3d.h"

void    clean_up(t_cub *cub)
{
    if (!cub)
        return;
    else
    {
        if (cub->map)
        {
            free_array(cub->map->grid, cub->map->height);
            free(cub->map);        
        }
        if (cub->img)
            mlx_destroy_image(cub->mlx, cub->img);
        if (cub->win)
            mlx_destroy_window(cub->mlx, cub->win);
        if (cub->mlx)
        {
            mlx_destroy_display(cub->mlx);
            free(cub->mlx);
        }
        if(cub->col)
        {
            if(cub->col->no_tex_p)
                free(cub->col->no_tex_p);
            if(cub->col->so_tex_p)
                free(cub->col->so_tex_p);
            if(cub->col->we_tex_p)
                free(cub->col->we_tex_p);
            if(cub->col->ea_tex_p)
                free(cub->col->ea_tex_p);           
            free(cub->col);
        }
        free(cub);
    }
    
}

void    free_array2(char **arr)
{
    int i;
   
    i = 0;
    if (!arr)
        return;
    while(arr[i])
    {
        free(arr[i]);
        i++;
    }
}

void	error_exit(t_cub *cub, char *msg, char** to_be_freed)
{
    ft_putstr_fd(msg, 2);    
    free_array2(to_be_freed);
    clean_up(cub);
    exit(1);
}