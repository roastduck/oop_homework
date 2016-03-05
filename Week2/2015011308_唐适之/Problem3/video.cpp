#include <iostream>
#include "video.h"

Video::Video(std::string _title, std::string _description)
    : title(_title), description(_description), isRent(false) {}

bool Video::rent_out(int days)
{
    if (is_rent())
    {
        std::cerr << "rent_out: Already been rent" << std::endl;
        return false;
    }
    isRent = true;
    rentDate = time(0);
    duration = days * 86400;
    return true;
}

bool Video::return_back()
{
    if (! is_rent())
    {
        std::cerr << "return_back: Not been rent" << std::endl;
        return false;
    }
    isRent = false;
    return true;
}

std::string Video::get_title() const
{
    return title;
}

std::string Video::get_description() const
{
    return description;
}

std::string Video::get_rent_date() const
{
    return ctime(&rentDate);
}

int Video::get_duration() const
{
    return duration / 86400;
}

std::string Video::get_return_date() const
{
    time_t ret(rentDate + duration);
    return ctime(&ret);
}

bool Video::is_rent() const
{
    return isRent;
}

bool Video::is_expired() const
{
    return is_rent() && rentDate+duration<time(0);
}

void Video::print() const
{
    std::cout << "title: " << get_title() << std::endl;
    std::cout << "description: " << get_description() << std::endl;
    std::cout << "the book has " << (is_rent() ? "" : "NOT ")
              << "been rent" << std::endl;
    if (is_rent())
    {
        std::cout << "rent date: " << get_rent_date();
        std::cout << "rent duration: " << get_duration()
                  << " day(s)" << std::endl;
        std::cout << "return date: " << get_return_date();
        std::cout << "the book has "
                  << (is_expired() ? "" : "NOT ")
                  << "been expired" << std::endl;
    }
    std::cout << std::endl;
}

