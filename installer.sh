#!/bin/bash

if g++ main.cpp -o mpa; then
  echo "Moving executable to /usr/local/bin/"
else
  if clangd main.cpp -o mpa; then
    echo "Moving executable to /usr/local/bin/"
  else
    echo "Install either the GNU complier collection (g++) or clangd"
    exit 1
  fi
fi 

if sudo mv mpa /usr/local/bin/mpa; then
  echo "mpa has been sucessfully installed!"
  exit 0
else
  echo "Something went wrong."
fi

