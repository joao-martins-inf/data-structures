# syntax=docker/dockerfile:1

FROM gcc:latest as development

WORKDIR /app

COPY . .

# RUN gcc install -r requirements.txt

# COPY . .
