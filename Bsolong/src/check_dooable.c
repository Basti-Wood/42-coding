#include "../includes/so_long.h"


static int map_height(char **map) {
    int h = 0;
    while (map[h]) h++;
    return h;
}

static char **duplicate_map(char **map) {
    int rows = map_height(map);
    char **copy = malloc(sizeof(char *) * (rows + 1));
    if (!copy) return NULL;
    for (int i = 0; i < rows; i++) {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i]) {
            while (--i >= 0) free(copy[i]);
            free(copy);
            return NULL;
        }
    }
    copy[rows] = NULL;
    return copy;
}

static void free_map_copy(char **map) {
    int i = 0;
    while (map[i]) {
        free(map[i]);
        i++;
    }
    free(map);
}

static int find_player_pos(char **map, int *x, int *y) {
    *y = 0;
    while (map[*y]) {
        *x = 0;
        while (map[*y][*x]) {
            if (map[*y][*x] == 'P') {
                return 1;
            }
            (*x)++;
        }
        (*y)++;
    }
    return 0;
}

static void floodfill(char **map, int start_x, int start_y, char wall) {
    int h = map_height(map);
    if (h == 0) return;
    int w = ft_strlen(map[0]);
    int max_size = h * w;
    t_point *queue = malloc(max_size * sizeof(t_point));
    if (!queue) return;

    int front = 0;
    int rear = 0;
    queue[rear++] = (t_point){start_x, start_y};
    map[start_y][start_x] = 'A';

    while (front < rear) {
        t_point current = queue[front++];
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int new_x = current.x + dx[i];
            int new_y = current.y + dy[i];
            if (new_y >=0 && new_y < h && new_x >=0 && new_x < (int)ft_strlen(map[new_y])) {
                char c = map[new_y][new_x];
                if (c != wall && c != 'A') {
                    map[new_y][new_x] = 'A';
                    if (rear < max_size) {
                        queue[rear++] = (t_point){new_x, new_y};
                    }
                }
            }
        }
    }
    free(queue);
}

int is_doable(t_data *data) {
    char **map_copy = duplicate_map(data->map);
    if (!map_copy) return 0;

    int px, py;
    if (!find_player_pos(map_copy, &px, &py)) {
        free_map_copy(map_copy);
        return 0;
    }

    floodfill(map_copy, px, py, data->content.wall);

    int y = 0;
    while (map_copy[y]) {
        int x = 0;
        while (map_copy[y][x]) {
            if (map_copy[y][x] == data->content.collect || map_copy[y][x] == data->content.exit) {
                free_map_copy(map_copy);
                return 0;
            }
            x++;
        }
        y++;
    }

    free_map_copy(map_copy);
    return 1;
}
