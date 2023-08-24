import type { Request, Response } from "express";

function hex(req: Request, res: Response) {
  console.log(req.body);
  return res.status(200);
}

export { hex };
