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




#ifndef _OCTOPUS_VERTEX_H_
#define _OCTOPUS_VERTEX_H_
#include"../hash/khash.h"

// TODO replace this definition with yours

struct vertex_t {
uint64_t key;
};

//the key of the vertex is saved by the hash 

typedef struct vertex_t vertex_t;


KHASH_MAP_INIT_INT64 (vertices, vertex_t);

//you dont (de/)malloc for the struct itself
void vertex_init (vertex_t * vertex);

void vertex_destroy(vertex_t *vertex);

vertex_t * vertex_dup(vertex_t *vertex);

//remove frames from the msg
void vertex_deserialize(khash_t (vertices) * hash,zmsg_t *msg);

//add frames to the msg
zmsg_t * vertex_serialize(zmsg_t *msg,vertex_t *vertex);

//iter should be at the beginning of the vertex
// add frames to the prefix
void vertex_db_to_msg(zmsg_t *prefix,leveldb_iterator_t *iter);

// remove frames from the message
void vertex_db_msg_to_db(dbo_t *dbo,zmsg_t *msg);


void vertex_db_destroy(dbo_t *dbo,leveldb_iterator_t *iter);

//iterator is moved one vertex position
void vertex_iter_next(leveldb_iterator_t *iter);

#endif
