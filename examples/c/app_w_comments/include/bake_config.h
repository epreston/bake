/*
                                   )
                                  (.)
                                  .|.
                                  | |
                              _.--| |--._
                           .-';  ;`-'& ; `&.
                          \   &  ;    &   &_/
                           |"""---...---"""|
                           \ | | | | | | | /
                            `---.|.|.|.---'

 * This file is generated by bake.lang.c for your convenience. Headers of
 * dependencies will automatically show up in this file. Include bake_config.h
 * in your main project file. Do not edit! */

#ifndef APP_W_COMMENTS_BAKE_CONFIG_H
#define APP_W_COMMENTS_BAKE_CONFIG_H

/* Headers of public dependencies */
/* No dependencies */

/* Headers of private dependencies */
#ifdef APP_W_COMMENTS_IMPL
/* No dependencies */
#endif

/* Convenience macro for exporting symbols */
#if APP_W_COMMENTS_IMPL && defined _MSC_VER
#define APP_W_COMMENTS_EXPORT __declspec(dllexport)
#elif APP_W_COMMENTS_IMPL
#define APP_W_COMMENTS_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define APP_W_COMMENTS_EXPORT __declspec(dllimport)
#else
#define APP_W_COMMENTS_EXPORT
#endif

#endif
