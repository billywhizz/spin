const api = {
  socket: {
    parameters: ['i32', 'i32', 'i32'],
    result: 'i32'
  },
  setsockopt: {
    parameters: ['i32', 'i32', 'i32', 'pointer', 'i32'],
    result: 'i32'
  },
  bind: {
    parameters: ['i32', 'pointer', 'i32'],
    pointers: [, 'const sockaddr*'],
    result: 'i32'
  },
  connect: {
    parameters: ['i32', 'pointer', 'i32'],
    pointers: [, 'const sockaddr*'],
    result: 'i32'
  },
  listen: {
    parameters: ['i32', 'i32'],
    result: 'i32'
  },
  close: {
    parameters: ['i32'],
    result: 'i32'
  },
  accept4: {
    parameters: ['i32', 'pointer', 'pointer', 'i32'],
    pointers: [, 'sockaddr*', 'socklen_t*'],
    result: 'i32'
  },
  send: {
    parameters: ['i32', 'pointer', 'i32', 'u32'],
    result: 'i32'
  },
  recv: {
    parameters: ['i32', 'pointer', 'u32', 'i32'],
    result: 'i32'
  },
  read: {
    parameters: ['i32', 'pointer', 'i32'],
    result: 'i32'
  },
  pipe2: {
    parameters: ['pointer', 'i32'],
    pointers: ['int*'],
    result: 'i32'
  },
  dup2: {
    parameters: ['i32', 'i32'],
    result: 'i32'
  },
}

const includes = [
  'sys/socket.h',
  'arpa/inet.h',
  'sys/un.h',
  'sys/ioctl.h',
  'net/if.h',
  'linux/if_packet.h',
  'netinet/tcp.h',
  'netinet/if_ether.h',
  'sys/types.h',
  'sys/sendfile.h',
  "unistd.h"
]
const name = 'net'

export { api, includes, name }
