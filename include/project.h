/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef BAKE_PROJECT_H_
#define BAKE_PROJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bake_project_type {
    BAKE_APPLICATION = 1,   /* Executable project in bake package store */
    BAKE_PACKAGE = 2,       /* Library project in bake package store */
    BAKE_TOOL = 3           /* Executable project accessible globally */
} bake_project_type;

/* Driver required by project with its configuration */
typedef struct bake_project_driver {
    bake_driver *driver;
    void *json;
    ut_ll attributes;
} bake_project_driver;

struct bake_project {
    /* Project properties (managed by bake core) */
    char *path;             /* Project path */
    char *id;               /* Project id */
    bake_project_type type; /* Project kind */
    char *version;          /* Project version */
    char *repository;       /* Project repository */
    char *author;           /* Project author */
    char *description;      /* Project description */
    char *language;         /* Project programming language */
    bool public;            /* Is package public or private */
    ut_ll use;              /* Project dependencies */
    ut_ll use_private;      /* Local dependencies (not visible to dependees) */
    ut_ll use_build;        /* Packages only required by the build */
    ut_ll link;             /* All resolved dependencies package must link with */
    ut_ll sources;          /* Paths to source files */
    ut_ll includes;         /* Paths to include files */
    bool keep_artefact;     /* Keep artefact when cleaning project */
    char *dependee_json;    /* Build instructions for dependees */

    ut_ll drivers;          /* Drivers used to build this project */
    bake_project_driver *language_driver; /* Driver loaded for the language */

    char *artefact;         /* Name of artefact generated by project */
    char *artefact_path;    /* Project path where artefact will be stored */
    char *artefact_file;    /* Project path including artefact name */
    char *bin_path;         /* Project bin path (not including platform) */
    char *cache_path;       /* Project path containing temporary build files */

    /* Direct access to the parson JSON data */
    void *json;

    /* Runtime status (managed by language binding) */
    bool error;
    bool freshly_baked;
    bool changed;

    /* Should project be rebuilt (managed by bake action) */
    bool artefact_outdated;
    bool sources_outdated;

    /* Dependency administration (managed by crawler) */
    int unresolved_dependencies; /* number of dependencies still to be built */
    ut_ll dependents; /* projects that depend on this project */
    bool built;

    /* Files to be cleaned other than objects and artefact (populated by
     * language binding) */
    ut_ll files_to_clean;

    /* Interface for bake plugin */
    bake_attribute* (*get_attr)(const char *name);
    char* (*get_attr_string)(const char *name);
    bool (*get_attr_bool)(const char *name);
    void (*add_build_dependency)(const char *file);
    void (*clean)(const char *file);
};

#ifdef __cplusplus
}
#endif

#endif
