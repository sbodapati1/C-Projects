#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;

  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}

// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
LLPath *enqueue_path(LLPath *q, Path path) {
  // YOUR CODE HERE
  // This code was borrowed from the Professor's demos.
    LLPath *newnode = calloc(1, sizeof(LLPath));
    newnode->val = path;
    if (q == NULL) {
       return newnode;
    }
    LLPath *cur = q;
    while(cur->next != NULL) {
       cur = cur->next;
    }
    cur->next = newnode;
    return q;
  }

bool dequeue_path(LLPath **q, Path *ret) {
  // YOUR CODE HERE
  if (*q == NULL) {
    return false;
  }
  *ret = (*q)->val;
  LLPath *freethis = *q;
  *q = (*q)->next;
  free(freethis);
  return true;
}

// We wrote these in class.
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

void graph_add_edge(Graph *g, int i, int j) {
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;

  for (int i=0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)");
  }
  for (int i=0; i < path.steps; i++) {
    printf("%s%d",
        (i == 0) ? "" : " -> ",
        path.vertices_visited[i]);
  }
  puts("");
}

// Breadth-first search!
Path graph_find_path_bfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  // This code was borrowed from the Professor's code.
  LLint *visited = NULL;
  LLPath *to_visit = NULL;
  Path newpath = {0, {0}};
  Path empty = {0, {0}};
  Path new = path_extend(newpath, i);
  to_visit = enqueue_path(to_visit, new);
  int current = i;
  int size = (g->vertices)/2;
  if (j > size){
      return empty;
  }
  if (current == j) {
      newpath = path_extend(newpath, current);
      return newpath;
    }
  while(to_visit != NULL){
    dequeue_path(&to_visit, &new);
    visited = add_to_set(visited, current);
    for(int neighbor = i; neighbor < g -> vertices; neighbor++) {
      if (graph_has_edge(g, current, neighbor) && !set_contains(visited, neighbor)) {
	new = path_extend(new, neighbor);
        to_visit = enqueue_path(to_visit, new);
      }
    if(sizeof to_visit > sizeof g){
	    break;
    }
    }
    return new;
  }
  return empty;
}

// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  // YOUR CODE HERE
  LLint *visited = NULL;
  LLPath *to_visit = NULL;
  Path newpath = {0, {0}};
  Path empty = {0, {0}};
  Path new = path_extend(newpath, i);
  to_visit = enqueue_path(to_visit, new);
  int size = (g->vertices)/2;
  if (j > size){
      return empty;
  }
  if (i == j) {
      newpath = path_extend(newpath, i);
      return newpath;
    }
    while(to_visit != NULL){
      dequeue_path(&to_visit, &new);
      visited = add_to_set(visited, i);
      for(int neighbor = i; neighbor < g -> vertices; neighbor++) {
      if (graph_has_edge(g, i, neighbor) && !set_contains(visited, neighbor)) {
        new = path_extend(new, neighbor);
        to_visit = enqueue_path(to_visit, new);
      }
    if(sizeof to_visit > sizeof g){
            break;
    }
    }
    return new;
    }
  return empty;
}

// Free the Graph
void graph_destroy(Graph **g){
  free((*g)->matrix);
  free(*g);
  *g = NULL;
}
