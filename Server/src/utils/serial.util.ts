import dotenv from "dotenv";
dotenv.config();
import { SerialPort } from "serialport";

const port = new SerialPort({
  path: process.env.SERIAL_PORT as string,
  baudRate: parseInt(process.env.SERIAL_BAUDRATE as string),
});

export { port as serialPort };
