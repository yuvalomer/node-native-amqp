{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "connection.cpp", "AMQPConsumer.cpp" ],
      "libraries": [ "/usr/local/lib/libSimpleAmqpClient.so" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}