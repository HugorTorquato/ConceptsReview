
# Prevent surprises with a fixed version
FROM ubuntu:22.04

# Install what i need to compile and build things in linux. So far:
RUN apt-get update && \
    apt-get install -y build-essential cmake tar gcc g++ git ca-certificates && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set up Google Test using FetchContent
WORKDIR /usr/src/gtest

# Clone Google Test repository and build
RUN git clone --branch release-1.11.0 https://github.com/google/googletest.git .  && \
    cmake -B build  && \
    cmake --build build  && \
    cp -r build/lib/* /usr/local/lib  && \
    cp -r googletest/include/gtest /usr/local/include

# Clean up unnecessary files after build to save space
RUN rm -rf /usr/src/gtest

# Set environment variables for C++20
ENV CC=gcc
ENV CXX=g++

WORKDIR /src
COPY ./src /src

# Run CMake to configure and build the project
#RUN cmake -Bbuild -H. && \
#    cmake --build build

# RUN echo "\n#Definer Aliases:" >> ~/.bashrc
# RUN echo "alias LBuild='cd /src && cmake -B ./out/build && cmake --build ./out/build'" >> ~/.bashrc
# RUN echo "alias LRun_Gtest='cd /src/out/build/parseXmlLibTests && ctest && cd -'" >> ~/.bashrc
# RUN echo "alias SimpleXML_test='./out/build/parseXmlExe/parseXmlExe resources/SimpleXML.xml'" >> ~/.bashrc

# Set the ENTRYPOINT to source the alias script
CMD [ "tail", "-f", "/dev/null"]
