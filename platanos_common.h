/*
    Copyright contributors as noted in the AUTHORS file.
                
    This file is part of PLATANOS.

    PLATANOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU Affero General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.
            
    PLATANOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.
        
    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef OCTOPUS_PLATANOS_COMMON_H_
#define OCTOPUS_PLATANOS_COMMON_H_

#include<zookeeper/zookeeper.h>


//inside online
void platanos_online_bind_points (zhandle_t * zh, char *octopus, char *comp_name,
                           char *res_name, char *bind_points[][50], int *size);


struct platanos_node_t;
typedef struct platanos_node_t platanos_node_t;
void platanos_node_destroy (platanos_node_t ** platanos_node);
platanos_node_t *platanos_node_dup (platanos_node_t * platanos_node);

#endif
