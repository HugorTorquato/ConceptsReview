# Use Red Hat UBI as the base image - RedHat Version 8
# Latest version but i don't want to change it everytime. So, i specfied the number here.
# Requires license ( .... dropping ths idea for now, using ubunto
#FROM registry.access.redhat.comubi8ubi8.10-1132

FROM ubuntu:22.04

# Install what i need to compile and build things in linux. So far
    # - GCC
    # - gdb
    # - cmake
    # - git - required to retrieve the gtest from git repository
RUN apt-get update && \
    apt-get install -y build-essential cmake tar gcc g++ git ca-certificates && \
    apt-get clean && rm -rf varlibaptlists

# Set up Google Test using FetchContent
WORKDIR usrsrcgtest

# Clone Google Test repository and build
RUN git clone --branch release-1.11.0 httpsgithub.comgooglegoogletest.git .  && \
    cmake -B build  && \
    cmake --build build  && \
    cp -r buildlib usrlocallib  && \
    cp -r googletestincludegtest usrlocalinclude

# Clean up unnecessary files after build to save space
RUN rm -rf usrsrcgtest

# Set environment variables for C++20
ENV CC=gcc
ENV CXX=g++

WORKDIR src
COPY .src src

# Run CMake to configure and build the project
#RUN cmake -Bbuild -H. && 
#    cmake --build build

# Default command to run your application
CMD [ tail, -f, devnull ]