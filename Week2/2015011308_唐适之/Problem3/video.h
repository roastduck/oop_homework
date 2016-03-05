#ifndef INCLUDED_VIDEO_H
#define INCLUDED_VIDEO_H

#include <ctime>
#include <string>

class Video
{
    const std::string title, description;
    bool isRent;
    time_t rentDate, duration;

public:
    Video(std::string _title, std::string _description="");

    bool rent_out(int days = 14);
    bool return_back();

    std::string get_title() const;
    std::string get_description() const;
    std::string get_rent_date() const;
    int get_duration() const;
    std::string get_return_date() const;
    bool is_rent() const;
    bool is_expired() const;
    void print() const;
};

#endif // INCLUDED_VIDEO_H
