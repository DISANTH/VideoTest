
#ifndef _V4L2UTIL_H_
#define _V4L2UTIL_H_

/* --------------------------------------------------------------------- */

struct v4l2_channel_list {
    const char * const name; /* channel name */
    unsigned freq; 	     /* channel frequency in kHz */
};

struct v4l2_channel_lists {
    const char * const name; /* channel list name */
    const struct v4l2_channel_list * const list;
    unsigned count;	     /* number of channels in channel list */
};

extern const struct v4l2_channel_lists v4l2_channel_lists[];

/* This list is sorted alphabetically on ISO code. The last item is
   denoted by a NULL pointer for the iso_code. */
struct v4l2_country_std_map {
    const char * const iso_code; /* The 2-character upper case ISO-3166 country code */
    v4l2_std_id std; 		 /* The TV standard(s) in use */
};

extern const struct v4l2_country_std_map v4l2_country_std_map[];

#endif
