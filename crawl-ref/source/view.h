/*
 *  File:       view.h
 *  Summary:    Misc function used to render the dungeon.
 *  Written by: Linley Henzell
 */


#ifndef VIEW_H
#define VIEW_H

#include "externs.h"

void init_char_table(char_set_type set);
void init_monsters_seens();

void beogh_follower_convert(monsters *monster, bool orc_hit = false);
void slime_convert(monsters *monster);
bool mons_near(const monsters *monster);
bool mon_enemies_around(const monsters *monster);

void find_features(const std::vector<coord_def>& features,
        unsigned char feature, std::vector<coord_def> *found);

bool magic_mapping(int map_radius, int proportion, bool suppress_msg,
                   bool force = false, bool deterministic = false,
                   bool circular = false,
                   coord_def origin = coord_def(-1, -1));
void reautomap_level();

bool noisy(int loudness, const coord_def& where, int who,
           bool mermaid = false);
bool noisy(int loudness, const coord_def& where, const char *msg = NULL,
           int who = -1, bool mermaid = false);
void blood_smell( int strength, const coord_def& where);
void handle_monster_shouts(monsters* monster, bool force = false);

class level_pos;
void show_map( level_pos &spec_place, bool travel_mode, bool allow_esc = false );
bool check_awaken(monsters* monster);
int count_detected_mons(void);
void clear_map(bool clear_items = true, bool clear_mons = true);
bool is_feature(int feature, const coord_def& where);
void get_item_glyph(const item_def *item, unsigned *glych,
                    unsigned short *glycol);
void get_mons_glyph(const monsters *mons, unsigned *glych,
                    unsigned short *glycol);
unsigned get_screen_glyph( int x, int y );
unsigned get_screen_glyph( const coord_def &p );
std::string stringize_glyph(unsigned glyph);
int multibyte_strlen(const std::string &s);

void get_item_symbol(unsigned int object, unsigned *ch,
                     unsigned short *colour);

// Applies ETC_ colour substitutions and brands.
unsigned real_colour(unsigned raw_colour);
int get_mons_colour(const monsters *mons);

void set_envmap_obj( const coord_def& where, int object );
unsigned get_envmap_char(int x, int y);
inline unsigned get_envmap_char(const coord_def& c) {
    return get_envmap_char(c.x, c.y);
}
bool inside_level_bounds(int x, int y);
bool inside_level_bounds(const coord_def &p);
int get_envmap_obj(int x, int y);
inline int get_envmap_obj(const coord_def& c) {
    return get_envmap_obj(c.x, c.y);
}
void set_envmap_detected_item(int x, int y, bool detected = true);
inline void set_envmap_detected_item(const coord_def& c, bool detected = true) {
    set_envmap_detected_item(c.x, c.y, detected);
}

void set_envmap_detected_mons(int x, int y, bool detected = true);
inline void set_envmap_detected_mons(const coord_def& c, bool detected = true) {
    set_envmap_detected_mons(c.x, c.y, detected);
}
void set_envmap_col( int x, int y, int colour, int flags );
void set_envmap_col( int x, int y, int colour );
bool is_sanctuary( const coord_def& p );
bool is_bloodcovered( const coord_def& p );

bool is_envmap_detected_item(int x, int y);
inline bool is_envmap_detected_item(const coord_def& c) {
    return is_envmap_detected_item(c.x, c.y);
}

bool is_envmap_detected_mons(int x, int y);
inline bool is_envmap_detected_mons(const coord_def& c) {
    return is_envmap_detected_mons(c.x, c.y);
}
bool is_envmap_item(int x, int y);
inline bool is_envmap_item(const coord_def& c) {
    return is_envmap_item(c.x, c.y);
}
void set_terrain_mapped( int x, int y );
inline void set_terrain_mapped( const coord_def& c ) {
    set_terrain_mapped(c.x,c.y);
}
void set_terrain_seen( int x, int y );
inline void set_terrain_seen( const coord_def& c ) {
    set_terrain_seen(c.x, c.y);
}
void set_terrain_changed( int x, int y );
bool is_terrain_known( int x, int y );
bool is_terrain_seen( int x, int y );
bool is_terrain_changed( int x, int y );
inline bool is_terrain_changed( const coord_def& c ) {
    return is_terrain_changed(c.x,c.y);
}
bool is_terrain_known(const coord_def &p);
bool is_terrain_mapped(const coord_def &p);
bool is_notable_terrain(dungeon_feature_type ftype);

inline bool is_terrain_seen(const coord_def &c)
{
    return (is_terrain_seen(c.x, c.y));
}

inline void set_terrain_changed(const coord_def &c)
{
    set_terrain_changed(c.x, c.y);
}

void clear_feature_overrides();
void add_feature_override(const std::string &text);
void clear_cset_overrides();
void add_cset_override(char_set_type set, const std::string &overrides);

unsigned grid_character_at(const coord_def &c);

std::string screenshot(bool fullscreen = false);

dungeon_char_type get_feature_dchar( dungeon_feature_type feat );
unsigned dchar_glyph(dungeon_char_type dchar);
unsigned get_sightmap_char(int feature);
unsigned get_magicmap_char(int feature);

bool view_update();
void view_update_at(const coord_def &pos);
#ifndef USE_TILE
void flash_monster_colour(const monsters *mon, unsigned char fmc_colour,
                          int fmc_delay);
#endif
void viewwindow(bool draw_it, bool do_updates);
void update_monsters_in_view();
void handle_seen_interrupt(monsters* monster);
void flush_comes_into_view();

dungeon_char_type dchar_by_name(const std::string &name);

void handle_terminal_resize(bool redraw = true);

#if defined(TARGET_OS_WINDOWS) || defined(TARGET_OS_DOS) || defined(USE_TILE)
unsigned short dos_brand( unsigned short colour,
                          unsigned brand = CHATTR_REVERSE);
#endif

#endif
