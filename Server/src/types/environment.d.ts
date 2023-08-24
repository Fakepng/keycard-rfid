declare global {
  namespace NodeJS {
    interface ProcessEnv {
      NODE_ENV: string;
      SERIAL_PORT: string;
      SERIAL_BAUDRATE: string;
    }
  }
}

export {};
