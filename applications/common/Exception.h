#pragma once

class Exception : std::exception {
public:
    explicit Exception(const std::string& message) : exceptionMessage(message) {}
    explicit Exception(const char* message) : exceptionMessage(message) {}
    ~Exception() noexcept override = default;
    const char * what() const noexcept override { return exceptionMessage.c_str(); }

private:
    std::string exceptionMessage;
};
