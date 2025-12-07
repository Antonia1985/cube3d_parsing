
#include"../inc/cub3d.h"

void	make_window(t_cub *cub)
{
   cub->mlx = mlx_init();
   if (!cub->mlx)
      error_exit(cub, "Failed to initialize MLX\n", NULL);

   mlx_get_screen_size(cub->mlx, &cub->mlx_data.screen_width,
      &cub->mlx_data.screen_height);
   cub->mlx_data.win_width = (int)round(cub->mlx_data.screen_width * 0.7);
   cub->mlx_data.win_height = (int)round(cub->mlx_data.screen_height * 0.7);
   
   cub->win = mlx_new_window(cub->mlx, cub->mlx_data.win_width,
         cub->mlx_data.win_height, "cub3D");
   if (!cub->win)
      error_exit(cub, "Failed to create window\n", NULL);
   
   
   cub->img = mlx_new_image(cub->mlx, cub->mlx_data.win_width, cub->mlx_data.win_height);
   if (!cub->img)
      error_exit(cub, "Failed to create image\n", NULL);

   cub->pxl_arr = mlx_get_data_addr(
      cub->img,
      &cub->mlx_data.bits_per_pixel,
      &cub->mlx_data.line_length,
      &cub->mlx_data.endian
   );
}
